/*
 * Image.h
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
 *  Created on: 30 avr. 2012
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <string>
#include <vector>
#include "Color.h"

class Image
{
public:
	Image(int width = 0, int height =0);
	virtual ~Image();

	bool create(int new_width, int new_height);
	bool loadFromFile(const std::string& filename);
	bool loadFromMemory(const void* data, int size);
	bool saveAs(const std::string& filename);
	bool resize(int width, int height);

	int width;
	int height;

	char* data();

private:
	char* m_data;
};

#endif /* IMAGE_H_ */
