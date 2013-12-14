/*
 * Vector3.cpp
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
 *  Created on: 24 avr. 2012
 */


#include "Vector3.h"
#include "ToStdString.h"
#include <cmath>

Vector3::Vector3(double x,double y, double z)
: x(x)
, y(y)
, z(z)
{}

Vector3::Vector3(const Vector3& vect)
: x(vect.x)
, y(vect.y)
, z(vect.z)
{}

Vector3& Vector3::operator=(const Vector3& vect)
{
	x = vect.x;
	y = vect.y;
	z = vect.z;
	return *this;
}

Vector3 Vector3::operator+(const Vector3& vect) const
{
	return Vector3(x + vect.x,y + vect.y, z+ vect.z);
}

Vector3 Vector3::operator-(const Vector3& vect) const
{
	return Vector3(x - vect.x,y - vect.y,z - vect.z);
}

Vector3& Vector3::operator+=(const Vector3& vect)
{
	x += vect.x;
	y += vect.y;
	z += vect.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& vect)
{
	x -= vect.x;
	y -= vect.y;
	z -= vect.z;
	return *this;
}

bool Vector3::operator==(const Vector3& vect) const
{
	return 	((x == vect.x) && (y == vect.y) && (z == vect.z));
}

bool Vector3::operator!=(const Vector3& vect) const
{
	return 	((x != vect.x) || (y != vect.y) || (z != vect.z));
}

Vector3 Vector3::operator*(double scalar) const
{
	return Vector3(x*scalar,y*scalar,z*scalar);
}

Vector3 Vector3::operator/(double scalar) const
{
	return Vector3(x/scalar,y/scalar,z/scalar);
}

Vector3& Vector3::operator*=(double scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

Vector3& Vector3::operator/=(double scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

double Vector3::dotProduct(const Vector3& vect) const 
{
	return x*vect.x+y*vect.y+z*vect.z;
}

Vector3 Vector3::crossProduct(const Vector3& vect) const
{
	return Vector3(	y*vect.z-z*vect.y,
					z*vect.x-x*vect.z,
					x*vect.y-y*vect.x);
}

double Vector3::norme() const
{
	return sqrt(x*x+y*y+z*z);
}

Vector3& Vector3::normalise()
{
	return ((*this)/=norme());
}

Vector3 Vector3::projectOn(const Vector3& vect) const
{
	Vector3 projectedVect(vect);
	double ratio = this->dotProduct(vect)/pow(vect.norme(),2);
	return projectedVect*ratio;
}

std::string Vector3::toStdString() const
{
	return " x:" + tostr(x) + " y:" + tostr(y) +" z:" + tostr(z);
}

