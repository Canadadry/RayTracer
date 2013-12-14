/*
 * Runtime.h
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

#ifndef RUNTIME_H_
#define RUNTIME_H_

#include <string>
#include <vector>

#include "Camera.h"
#include "RayTracer.h"
#include "Image.h"

class TiXmlNode;

class Runtime
{
public:
	Runtime();
	virtual ~Runtime();

	bool readConfigFile(const std::string& filename);
	void render();

private:
	RayTracer* m_rayTracer;
	std::vector<Image*> m_images;
	std::vector<Camera*> m_cameras;
	std::vector<std::string> m_outFilenames;

	bool readSceneNode(TiXmlNode* node);
	bool readCamerasNode(TiXmlNode* node);
	bool readCameraNode(TiXmlNode* node);
	bool readObjectsNode(TiXmlNode* node);
	bool readTriangleNode(TiXmlNode* node);
	bool readSphereNode(TiXmlNode* node);


};

#endif /* RUNTIME_H_ */
