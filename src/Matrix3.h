/*
 * Matrix3.h
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
 *  Created on: 12 mai 2012
 */

#ifndef MATRIX3_H_
#define MATRIX3_H_

#include "Vector3.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(const Matrix3& mat);
	Matrix3& operator=(const Matrix3& mat);
	Matrix3 operator+(const Matrix3& mat) const;
	Matrix3 operator-(const Matrix3& mat) const;
	Matrix3& operator+=(const Matrix3& mat);
	Matrix3& operator-=(const Matrix3& mat);
	bool operator==(const Matrix3& mat) const;
	bool operator!=(const Matrix3& mat) const;
	Matrix3 operator*(const Matrix3& mat) const ;
	Matrix3& operator*=(const Matrix3& mat);

	Matrix3 operator/(double scalar) const ;
	Matrix3& operator/=(double scalar);
	Matrix3 operator*(double scalar) const ;
	Matrix3& operator*=(double scalar);

	Vector3 operator*(const Vector3& vect) const ;

	Matrix3& loadIdentity();

	double det() const;
	Matrix3 getInversed() const;
	Matrix3& inverse();

	Matrix3 getTranspose() const;
	Matrix3& transpose();

	static Matrix3 identityMatrix();
	static Matrix3 fromBasis(const Vector3& vect1,const Vector3& vect2,const Vector3& vect3);

	double m11, m12, m13, m21, m22, m23,m31, m32, m33;

};

#endif /* MATRIX3_H_ */
