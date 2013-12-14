/*
 * Image.cpp
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

#include "Image.h"
#include <exception>
#include "ext/stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "ext/stb_image/stb_image_write.h"

std::string toLower(std::string str)
{
	for (std::string::iterator i = str.begin(); i != str.end(); ++i)
		*i = static_cast<char>(std::tolower(*i));
	return str;
}

Image::Image(int p_width, int p_height)
: width(p_width)
, height(p_height)
, m_data(NULL)
{

}

Image::~Image()
{
	if(m_data!=NULL) free(m_data);
}


bool Image::create(int new_width, int new_height)
{
	bool ret= true;
	width = new_width;
	height = new_height;

	if(width == 0 || height == 0)
	{
		ret = false;
	}
	else
	{
		if(m_data != NULL) free(m_data);
		m_data =  (char*) malloc(width*height*4*sizeof(char));
		memset (m_data,255,width*height*4*sizeof(char));
		if(m_data == NULL)
		{
			width = 0;
			height = 0;
			ret = false;
		}
	}
	return ret;
}

bool Image::loadFromFile(const std::string& filename)
{
	bool ret = true;
	int imgChannels = 0;
	unsigned char* ptr = stbi_load(filename.c_str(), &width,&height, &imgChannels, STBI_rgb_alpha);

	if (ptr)
	{
		create(width,height);
		memcpy(m_data, ptr, width*height*sizeof(Color));
		stbi_image_free(ptr);
	}
	else
	{
		fprintf(stderr,"Failed to load image \"%s\". Reason : %s\n",filename.c_str(),stbi_failure_reason());
		ret = false;
	}
	return ret;
}

bool Image::loadFromMemory(const void* filem_data, int size)
{
	bool ret = true;
	int imgChannels = 0;
	const unsigned char* buffer = (const unsigned char*)(filem_data);
	unsigned char* ptr = stbi_load_from_memory(buffer,size, &width,&height, &imgChannels, STBI_rgb_alpha);

	if (ptr)
	{
		create(width,height);
		memcpy(m_data, ptr, width*height*sizeof(Color));
		stbi_image_free(ptr);
	}
	else
	{
		fprintf(stderr,"Failed to load image from memory. Reason : %s\n",stbi_failure_reason());
		ret = false;
	}
	return ret;
}

bool Image::saveAs(const std::string& filename)
{
	if (width>0 && height >0)
	{
		if (filename.size() > 3)
		{
			// Extract the extension
			std::string extension = filename.substr(filename.size() - 3);

			if (toLower(extension) == "bmp")
			{
				// BMP format
				if (stbi_write_bmp(filename.c_str(), width, height, 4, m_data))
					return true;
			}
			else if (toLower(extension) == "tga")
			{
				// TGA format
				if (stbi_write_tga(filename.c_str(), width, height, 4, m_data))
					return true;
			}
			else if(toLower(extension) == "png")
			{
				// PNG format
				if (stbi_write_png(filename.c_str(), width, height, 4, m_data, 0))
					return true;
			}
			else
			{
				fprintf(stderr,"Failed to save image, unknown type\n");
				return false;
			}
		}
		else
		{
			fprintf(stderr,"Failed to save image, can't deduce type\n");
			return false;
		}
	}
	else
	{
		fprintf(stderr,"Failed to save image, empty image\n");
		return false;
	}
	return true;
}

bool Image::resize(int new_width, int new_height)
{
	if(new_width == 0 || new_height == 0)
	{
		return false;
	}
	return create(new_width,new_height);
}

char* Image::data()
{
	return m_data;
}
