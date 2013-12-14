/*
 * Vector3.h
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

#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <string>

class Vector3
{
public:
	explicit Vector3(double x =0.0 ,double y =0.0 , double z =0.0);
	Vector3(const Vector3& vect);
	Vector3& operator=(const Vector3& vect);
	Vector3 operator+(const Vector3& vect) const;
	Vector3 operator-(const Vector3& vect) const;
	Vector3& operator+=(const Vector3& vect);
	Vector3& operator-=(const Vector3& vect);
	bool operator==(const Vector3& vect) const;
	bool operator!=(const Vector3& vect) const;
	Vector3 operator*(double scalar) const ;
	Vector3 operator/(double scalar) const ;
	Vector3& operator*=(double scalar);
	Vector3& operator/=(double scalar);

	double dotProduct(const Vector3& vect) const ;
	Vector3 crossProduct(const Vector3& vect) const ;
	double norme() const ;
	Vector3& normalise();
	Vector3 projectOn(const Vector3& vect) const;


	std::string toStdString() const;

	double x;
	double y;
	double z;
};

#endif /* VECTOR3_H_ */
