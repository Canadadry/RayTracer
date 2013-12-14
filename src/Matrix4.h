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


#ifndef MATRIX4_H_
#define MATRIX4_H_

#include <string>
#include "Vector3.h"
#include "Point3.h"


const int matrix_dim = 4;
const int nb_coef = matrix_dim*matrix_dim;

class Matrix4
{
public:
	//ctor
	Matrix4();
	Matrix4(double* coef);
	Matrix4(const Matrix4& mat);

	// matrix operator
	Matrix4& operator=(const Matrix4& mat);
	Matrix4 operator+(const Matrix4& mat) const;
	Matrix4 operator-(const Matrix4& mat) const;
	Matrix4& operator+=(const Matrix4& mat);
	Matrix4& operator-=(const Matrix4& mat);
	bool operator==(const Matrix4& mat) const;
	bool operator!=(const Matrix4& mat) const;
	Matrix4 operator*(const Matrix4& mat) const ;
	Matrix4& operator*=(const Matrix4& mat);
	
	//scalar operator
	Matrix4 operator/(double scalar) const ;
	Matrix4& operator/=(double scalar);
	Matrix4 operator*(double scalar) const ;
	Matrix4& operator*=(double scalar);
	
	//vector operator
	Vector3 operator*(const Vector3& vect) const ;

	//point operator
	Point3 operator*(const Point3& vect) const ;
	
	//geometry operation
	Matrix4& loadIdentity();
	Matrix4& translate(const Vector3& vect);
	Matrix4& rotate(double angle,const Vector3& axe);
	Matrix4& scale(double scaleX,double scaleY, double scaleZ);

	// static matrix
	static Matrix4 translationMatrix(const Vector3& vect);
	static Matrix4 rotationMatrix(double angle,const Vector3& axe);
	static Matrix4 scaleMatrix(double scaleX,double scaleY, double scaleZ);
	static Matrix4 identityMatrix();

	std::string toStdString() const;

	double m_coef[nb_coef];

};


#endif /* MATRIX4_H_ */
