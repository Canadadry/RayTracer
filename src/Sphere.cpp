/*
 * Sphere.cpp
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

#include "Sphere.h"
#include <cmath>

Sphere::Sphere(const Point3& center, double radius, const Color& color)
: m_center(center)
, m_radius(radius)
, m_color(color)
{}

Sphere::~Sphere(){}

Color Sphere::computeColorAtPoint(const Point3& point)
{
	return m_color;
}

bool Sphere::instersect(const Vector3& vect, const Point3& fromPoint)
{
	bool ret = false;

	// projection of the sphere center on the ray
	Vector3 vectFromOrigine = m_center - fromPoint;
	Vector3 vectToRay = vectFromOrigine-vectFromOrigine.projectOn(vect);

	if(vectToRay.norme() <= m_radius)
	{
		ret = true;
		double distProjToIntersec = sqrt(pow(m_radius,2) -  pow(vectToRay.norme(),2));
		Vector3 vectProjToIntersec(vect);
		vectProjToIntersec.normalise();
		vectProjToIntersec*=(-distProjToIntersec);
		lastIntersectionPoint = m_center.translate(vectToRay).translate(vectProjToIntersec);
	}

	return ret;
}

