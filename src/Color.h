/*
 * Color.h
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

#ifndef COLOR_H_
#define COLOR_H_

class Color
{
public:
	Color(unsigned char R,unsigned char G,unsigned char B,unsigned char A=255);
	Color(const Color& color);
	operator char *();
	virtual ~Color();

	Color& operator=(const Color& color);

	unsigned char r,g,b,a;

	static Color red;
	static Color blue;
	static Color green;
	static Color yellow;
	static Color cyan;
	static Color magenta;
	static Color white;
	static Color black;
	static Color transparent;
};

#endif /* COLOR_H_ */
