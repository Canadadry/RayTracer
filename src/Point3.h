/*
 * Point3.h
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
 *  Created on: 25 avr. 2012
 */

#ifndef POINT3_H_
#define POINT3_H_

#include "Vector3.h"

class Point3
{
public:
	Point3(double x=0.0, double y=0.0, double z=0.0);
	Point3(const Point3& point);
	Point3& operator=(const Point3& point);
	bool operator==(const Point3& point) const;
	bool operator!=(const Point3& point) const;

	Vector3 operator-(const Point3& point) const;
	Point3 translate(const Vector3& vect) const;

	double getDistanceTo(const Point3& point) const;

	std::string toStdString() const;

	double x,y,z;
};

#endif /* POINT3_H_ */
