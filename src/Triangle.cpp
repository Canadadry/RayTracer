/*
 * Triangle.cpp
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

#include "Triangle.h"
#include "Matrix3.h"

Triangle::Triangle(const Point3& p1,const Point3& p2,const Point3& p3,const Color& color)
: m_color(color)
{
	m_vertices[0] = p1;
	m_vertices[1] = p2;
	m_vertices[2] = p3;
}

bool Triangle::instersect(const Vector3& vect, const Point3& fromPoint)
{
	bool ret = false;
	Matrix3 basisChange = Matrix3::fromBasis(m_vertices[0]-fromPoint,m_vertices[1]-fromPoint,m_vertices[2]-fromPoint).inverse();
	Vector3 vectInNewBasis = basisChange*vect;
	if(vectInNewBasis.x>=0 && vectInNewBasis.y>=0 && vectInNewBasis.z>=0)
	{
		lastIntersectionPoint = fromPoint.translate(vect/(vectInNewBasis.x+vectInNewBasis.y+vectInNewBasis.z));
		ret = true;
	}
	return ret;
}

Color Triangle::computeColorAtPoint(const Point3& point)
{
	return m_color;
}
