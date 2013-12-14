/*
 * Runtime.cpp
 *
 * RayTracer - Copyright (c) 2012 - Jerome Mourey
 *
 * This software is provided 'as-is', without any express or
 * implied warranty. In no event will the authors be held
 * liable for any damages arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute
 * it freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented;
 *    you must not claim that you wrote the original software.
 *    If you use this software in a product, an acknowledgment
 *    in the product documentation would be appreciated but
 *    is not required.
 * 
 * 2. Altered source versions must be plainly marked as such,
 *    and must not be misrepresented as being the original software.
 * 
 * 3. This notice may not be removed or altered from any
 *    source distribution.
 *
 *  Created on: 13 mai 2012
 */

#include "Runtime.h"
#include "ext/tinyxml/tinyxml.h"
#include "RayTracer.h"
#include "Camera.h"
#include "Sphere.h"
#include "Triangle.h"

Runtime::Runtime()
: m_rayTracer(new RayTracer())
, m_images()
, m_cameras()
, m_outFilenames()
{}

Runtime::~Runtime()
{
	// TODO coorect memory leak
}

void Runtime::render()
{
	for(unsigned int i=0; i<m_cameras.size(); i++)
	{
		m_rayTracer->render(*m_cameras[i],*m_images[i]);
		m_images[i]->saveAs(m_outFilenames[i]);
	}
}

bool Runtime::readConfigFile(const std::string& filename)
{
	TiXmlDocument doc(filename.c_str());
	if(!doc.LoadFile())
	{
		printf("RayTracer couldn't open file :%s\n", filename.c_str());
		return false;
	}

	TiXmlHandle handle(&doc);
	return readSceneNode(handle.ToNode()->FirstChild());
}

bool Runtime::readSceneNode(TiXmlNode* node)
{
	TiXmlElement* pElement = node->ToElement();

	int R,G,B;
	pElement->QueryIntAttribute("colorR",&(R));
	pElement->QueryIntAttribute("colorG",&(G));
	pElement->QueryIntAttribute("colorB",&(B));

	m_rayTracer->setBackgroundColor(Color(R,G,B));

	for(TiXmlNode* pChild = node->FirstChild(); pChild != 0; pChild = pChild->NextSibling())
	{

		switch ( pChild->Type() )
		{
			case TiXmlNode::TINYXML_DOCUMENT:
				printf("Bad node position");
				return false;

			case TiXmlNode::TINYXML_ELEMENT:
				if( std::string(pChild->Value()) == "cameras")
				{
					if(readCamerasNode(pChild) == false) return false;
				}
				else if( std::string(pChild->Value()) == "objects")
				{
					if(readObjectsNode(pChild) == false) return false;
				}
				else
				{
					printf("unsupported node: %s\n",pChild->Value());
					return false;
				}
				break;

			case TiXmlNode::TINYXML_COMMENT: break;
			case TiXmlNode::TINYXML_UNKNOWN: break;
			case TiXmlNode::TINYXML_TEXT:
				printf("Unsupported Text");
				return false;
				break;

			case TiXmlNode::TINYXML_DECLARATION: break;
			default: break;

		}//switch

	}//for

	return true;
}

bool Runtime::readCamerasNode(TiXmlNode* node)
{

	for(TiXmlNode* pChild = node->FirstChild(); pChild != 0; pChild = pChild->NextSibling())
	{

		switch ( pChild->Type() )
		{
			case TiXmlNode::TINYXML_DOCUMENT:
				printf("Bad node position");
				return false;

			case TiXmlNode::TINYXML_ELEMENT:
				if( std::string(pChild->Value()) == "camera")
				{
					if(readCameraNode(pChild) == false) return false;
				}
				else
				{
					printf("unsupported node: %s\n",pChild->Value());
					return false;
				}
				break;

			case TiXmlNode::TINYXML_COMMENT: break;
			case TiXmlNode::TINYXML_UNKNOWN: break;
			case TiXmlNode::TINYXML_TEXT:
				printf("Unsupported Text");
				return false;
				break;

			case TiXmlNode::TINYXML_DECLARATION: break;
			default: break;

		}//switch

	}//for

	return true;
}

bool Runtime::readCameraNode(TiXmlNode* node)
{
	TiXmlElement* pElement = node->ToElement();

	// camera
	Point3 pos;
	pElement->QueryDoubleAttribute("posx",&(pos.x));
	pElement->QueryDoubleAttribute("posy",&(pos.y));
	pElement->QueryDoubleAttribute("posz",&(pos.z));

	Point3 eye;
	pElement->QueryDoubleAttribute("eyex",&(eye.x));
	pElement->QueryDoubleAttribute("eyey",&(eye.y));
	pElement->QueryDoubleAttribute("eyez",&(eye.z));

	double fovx=90.0;
	pElement->QueryDoubleAttribute("fovx",&fovx);

	Camera* loc_camera = new Camera(pos,eye,Vector3(1,0,0),fovx);
	m_cameras.push_back(loc_camera);

	// image
	int width=200;
	pElement->QueryIntAttribute("width",&width);

	int height=200;
	pElement->QueryIntAttribute("height",&height);

	Image* loc_image = new Image(width,height);
	m_images.push_back(loc_image);

	char outFileName[255]="";
	strcpy(outFileName,pElement->Attribute("orientation"));

	m_outFilenames.push_back(outFileName);

	return true;
}

bool Runtime::readObjectsNode(TiXmlNode* node)
{

	for(TiXmlNode* pChild = node->FirstChild(); pChild != 0; pChild = pChild->NextSibling())
	{

		switch ( pChild->Type() )
		{
			case TiXmlNode::TINYXML_DOCUMENT:
				printf("Bad node position");
				return false;

			case TiXmlNode::TINYXML_ELEMENT:
				if( std::string(pChild->Value()) == "triangle")
				{
					if(readTriangleNode(pChild) == false) return false;
				}
				else if( std::string(pChild->Value()) == "sphere")
				{
					if(readSphereNode(pChild) == false) return false;
				}
				else
				{
					printf("unsupported node: %s\n",pChild->Value());
					return false;
				}
				break;

			case TiXmlNode::TINYXML_COMMENT: break;
			case TiXmlNode::TINYXML_UNKNOWN: break;
			case TiXmlNode::TINYXML_TEXT:
				printf("Unsupported Text");
				return false;
				break;

			case TiXmlNode::TINYXML_DECLARATION: break;
			default: break;

		}//switch

	}//for

	return true;
}

bool Runtime::readTriangleNode(TiXmlNode* node)
{
	TiXmlElement* pElement = node->ToElement();

	Point3 pointA;
	pElement->QueryDoubleAttribute("Ax",&(pointA.x));
	pElement->QueryDoubleAttribute("Ay",&(pointA.y));
	pElement->QueryDoubleAttribute("Az",&(pointA.z));

	Point3 pointB;
	pElement->QueryDoubleAttribute("Bx",&(pointB.x));
	pElement->QueryDoubleAttribute("By",&(pointB.y));
	pElement->QueryDoubleAttribute("Bz",&(pointB.z));

	Point3 pointC;
	pElement->QueryDoubleAttribute("Cx",&(pointC.x));
	pElement->QueryDoubleAttribute("Cy",&(pointC.y));
	pElement->QueryDoubleAttribute("Cz",&(pointC.z));

	int R,G,B;
	pElement->QueryIntAttribute("colorR",&(R));
	pElement->QueryIntAttribute("colorG",&(G));
	pElement->QueryIntAttribute("colorB",&(B));

	m_rayTracer->addObject(new Triangle(pointA,pointB,pointC,Color(R,G,B)));

	return true;

}

bool Runtime::readSphereNode(TiXmlNode* node)
{
	TiXmlElement* pElement = node->ToElement();

	Point3 center;
	pElement->QueryDoubleAttribute("centerx",&(center.x));
	pElement->QueryDoubleAttribute("centery",&(center.y));
	pElement->QueryDoubleAttribute("centerz",&(center.z));

	double radius = 10.0;
	pElement->QueryDoubleAttribute("radius",&(radius));

	int R,G,B;
	pElement->QueryIntAttribute("colorR",&(R));
	pElement->QueryIntAttribute("colorG",&(G));
	pElement->QueryIntAttribute("colorB",&(B));

	m_rayTracer->addObject(new Sphere(center,radius,Color(R,G,B)));

	return true;
}


