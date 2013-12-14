/*
 * Color.cpp
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

#include "Color.h"

Color Color::red		= Color(255,  0,  0);
Color Color::blue		= Color(  0,  0,255);
Color Color::green		= Color(  0,255,  0);
Color Color::yellow		= Color(255,255,  0);
Color Color::magenta	= Color(255,  0,255);
Color Color::cyan		= Color(  0,255,255);
Color Color::white		= Color(255,255,255);
Color Color::black		= Color(  0,  0,  0);
Color Color::transparent	= Color(  0,  0,  0,  0);

Color::Color(unsigned char R,unsigned char G,unsigned char B,unsigned char A)
: r(R)
, g(G)
, b(B)
, a(A)
{}

Color::Color(const Color& color)
: r(color.r)
, g(color.g)
, b(color.b)
, a(color.a)
{}

Color::~Color()
{}

Color& Color::operator=(const Color& color)
{
	r=color.r;
	g=color.g;
	b=color.b;
	a=color.a;
	return *this;
}

Color::operator char *()
		{
	return (char*)this;
		}


