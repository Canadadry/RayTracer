/*
 * RayTracer.cpp
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
 *  Created on: 29 avr. 2012
 */

#include "RayTracer.h"
#include  "Point3.h"
#include "Vector3.h"
#include "Image.h"
#include <float.h>

RayTracer::RayTracer()
: m_scene()
, m_backgroundColor(Color::transparent)
{}

RayTracer::~RayTracer()
{
	while(m_scene.size()>0)
	{
		delete m_scene.back();
		m_scene.pop_back();
	}
}

void RayTracer::addObject(Object* object)
{
	m_scene.push_back(object);
}

void RayTracer::setBackgroundColor(const Color& bgColor)
{
	m_backgroundColor = bgColor;
}

void RayTracer::render(const Camera& camera,Image& outImage)
{
	if(m_scene.size()>0)
	{
		std::vector<Vector3> rayList;
		camera.populateRayListToCast(rayList,outImage.width,outImage.height);
		double minDist = DBL_MAX;
		Color colorForMinDist(Color::black);
		Object* currentObject;
		char* outImageData = outImage.data();
		for(int j=0;j<outImage.height;j++)
		{
			for(int i=0;i<outImage.width;i++)
			{
				minDist = DBL_MAX;
				for(unsigned int k=0;k<m_scene.size();k++)
				{
					currentObject = m_scene[k];
					if(currentObject->instersect(rayList[i+j*outImage.width],camera.getPosition()))
					{
						if(minDist > currentObject->lastIntersectionPoint.getDistanceTo(camera.getPosition()) )
						{
							minDist = currentObject->lastIntersectionPoint.getDistanceTo(camera.getPosition()) ;
							colorForMinDist = currentObject->computeColorAtPoint(currentObject->lastIntersectionPoint);
						}
					}
				}
				if(minDist < DBL_MAX)
				{
					outImageData[(i+j*outImage.width)*4+0] = colorForMinDist.r;
					outImageData[(i+j*outImage.width)*4+1] = colorForMinDist.g;
					outImageData[(i+j*outImage.width)*4+2] = colorForMinDist.b;
					outImageData[(i+j*outImage.width)*4+3] = colorForMinDist.a;
				}
				else
				{
					outImageData[(i+j*outImage.width)*4+0] = m_backgroundColor.r;
					outImageData[(i+j*outImage.width)*4+1] = m_backgroundColor.g;
					outImageData[(i+j*outImage.width)*4+2] = m_backgroundColor.b;
					outImageData[(i+j*outImage.width)*4+3] = m_backgroundColor.a;
				}

			}
		}
	}
}


