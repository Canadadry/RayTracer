/*
 * Triangle.h
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
 *  Created on: 11 mai 2012
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Object.h"
#include "Point3.h"
#include "Color.h"

class Triangle: public Object
{
public:
	Triangle(const Point3& p1,const Point3& p2,const Point3& p3,const Color& color = Color::black);
	virtual bool instersect(const Vector3& vect, const Point3& fromPoint);
	virtual Color computeColorAtPoint(const Point3& point);

private:
	Point3 m_vertices[3];
	Color  m_color;
};

#endif /* TRIANGLE_H_ */
