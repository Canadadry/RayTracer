/*
 * Point3.cpp
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

#include "Point3.h"
#include "ToStdString.h"

Point3::Point3(double x, double y, double z)
: x(x)
, y(y)
, z(z)
{}

Point3::Point3(const Point3& point)
: x(point.x)
, y(point.y)
, z(point.z)
{}

Point3& Point3::operator=(const Point3& point)
{
	x = point.x;
	y = point.y;
	z = point.z;
	return *this;
}

bool Point3::operator==(const Point3& point) const
{
	return 	((x == point.x) && (y == point.y) && (z == point.z));
}

bool Point3::operator!=(const Point3& point) const
{
	return ((x != point.x) || (y != point.y) || (z != point.z));
}

Vector3 Point3::operator-(const Point3& point) const
{
	return Vector3(x-point.x,y-point.y,z-point.z);
}

Point3 Point3::translate(const Vector3& vect) const
{
	return Point3(x+vect.x,y+vect.y,z+vect.z);
}

double Point3::getDistanceTo(const Point3& point) const
{
	Vector3 vect = (*this)-point;
	return vect.norme();
}

std::string Point3::toStdString() const
{
	return " x:" + tostr(x) + " y:" + tostr(y) +" z:" + tostr(z);
}


