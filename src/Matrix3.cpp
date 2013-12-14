/*
 * Matrix3.cpp
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

#include "Matrix3.h"
#include <cmath>

Matrix3::Matrix3()
: m11(0.0) , m12(0.0) , m13(0.0)
, m21(0.0) , m22(0.0) , m23(0.0)
, m31(0.0) , m32(0.0) , m33(0.0)
{}

Matrix3::Matrix3(const Matrix3& mat)
: m11(mat.m11) , m12(mat.m12) , m13(mat.m13)
, m21(mat.m21) , m22(mat.m22) , m23(mat.m23)
, m31(mat.m31) , m32(mat.m32) , m33(mat.m33)
{}

Matrix3& Matrix3::operator=(const Matrix3& mat)
{
	m11 = mat.m11;
	m12 = mat.m12;
	m13 = mat.m13;
	m21 = mat.m21;
	m22 = mat.m22;
	m23 = mat.m23;
	m31 = mat.m31;
	m32 = mat.m32;
	m33 = mat.m33;

	return *this;
}

Matrix3 Matrix3::operator+(const Matrix3& mat) const
{
	Matrix3 tmp(mat);
	tmp.m11 += m11;
	tmp.m12 += m12;
	tmp.m13 += m13;
	tmp.m21 += m21;
	tmp.m22 += m22;
	tmp.m23 += m23;
	tmp.m31 += m31;
	tmp.m32 += m32;
	tmp.m33 += m33;

	return tmp;
}

Matrix3 Matrix3::operator-(const Matrix3& mat) const
{
	Matrix3 tmp(mat);
	tmp.m11 -= m11;
	tmp.m12 -= m12;
	tmp.m13 -= m13;
	tmp.m21 -= m21;
	tmp.m22 -= m22;
	tmp.m23 -= m23;
	tmp.m31 -= m31;
	tmp.m32 -= m32;
	tmp.m33 -= m33;

	return tmp;
}

Matrix3& Matrix3::operator+=(const Matrix3& mat)
{
	m11 += mat.m11;
	m12 += mat.m12;
	m13 += mat.m13;
	m21 += mat.m21;
	m22 += mat.m22;
	m23 += mat.m23;
	m31 += mat.m31;
	m32 += mat.m32;
	m33 += mat.m33;

	return *this;
}

Matrix3& Matrix3::operator-=(const Matrix3& mat)
{
	m11 -= mat.m11;
	m12 -= mat.m12;
	m13 -= mat.m13;
	m21 -= mat.m21;
	m22 -= mat.m22;
	m23 -= mat.m23;
	m31 -= mat.m31;
	m32 -= mat.m32;
	m33 -= mat.m33;

	return *this;
}

bool Matrix3::operator==(const Matrix3& mat) const
{
	return (m11 == mat.m11 &&
	m12 == mat.m12 &&
	m13 == mat.m13 &&
	m21 == mat.m21 &&
	m22 == mat.m22 &&
	m23 == mat.m23 &&
	m31 == mat.m31 &&
	m32 == mat.m32 &&
	m33 == mat.m33);
}

bool Matrix3::operator!=(const Matrix3& mat) const
{
	return (m11 != mat.m11 ||
			m12 != mat.m12 ||
			m13 != mat.m13 ||
			m21 != mat.m21 ||
			m22 != mat.m22 ||
			m23 != mat.m23 ||
			m31 != mat.m31 ||
			m32 != mat.m32 ||
			m33 != mat.m33);
}

Matrix3 Matrix3::operator*(const Matrix3& mat) const
{
	Matrix3 tmp;
	tmp.m11 = mat.m11*m11+mat.m21*m12+mat.m31*m13;
	tmp.m12 = mat.m12*m11+mat.m22*m12+mat.m32*m13;
	tmp.m13 = mat.m13*m11+mat.m23*m12+mat.m33*m13;
	tmp.m21 = mat.m11*m21+mat.m21*m22+mat.m31*m23;
	tmp.m22 = mat.m12*m21+mat.m22*m22+mat.m32*m23;
	tmp.m23 = mat.m13*m21+mat.m23*m22+mat.m33*m23;
	tmp.m31 = mat.m11*m31+mat.m21*m32+mat.m31*m33;
	tmp.m32 = mat.m12*m31+mat.m22*m32+mat.m32*m33;
	tmp.m33 = mat.m13*m31+mat.m23*m32+mat.m33*m33;

	return tmp;
}

Matrix3& Matrix3::operator*=(const Matrix3& mat)
{
	(*this) = this->operator*(mat);
	return (*this);
}

Vector3 Matrix3::operator*(const Vector3& vect) const
{
	Vector3 out;
	out.x = vect.x * m11 + vect.y * m12 + vect.z*m13;
	out.y = vect.x * m21 + vect.y * m22 + vect.z*m23;
	out.z = vect.x * m31 + vect.y * m32 + vect.z*m33;
	return out;
}

Matrix3 Matrix3::operator/(double scalar) const
{
	Matrix3 tmp(*this);
	tmp.m11 /= scalar;
	tmp.m12 /= scalar;
	tmp.m13 /= scalar;
	tmp.m21 /= scalar;
	tmp.m22 /= scalar;
	tmp.m23 /= scalar;
	tmp.m31 /= scalar;
	tmp.m32 /= scalar;
	tmp.m33 /= scalar;

	return tmp;
}

Matrix3& Matrix3::operator/=(double scalar)
{
	(*this) = this->operator/(scalar);
	return (*this);
}

Matrix3 Matrix3::operator*(double scalar) const
{
	Matrix3 tmp(*this);
	tmp.m11 *= scalar;
	tmp.m12 *= scalar;
	tmp.m13 *= scalar;
	tmp.m21 *= scalar;
	tmp.m22 *= scalar;
	tmp.m23 *= scalar;
	tmp.m31 *= scalar;
	tmp.m32 *= scalar;
	tmp.m33 *= scalar;

	return tmp;
}

Matrix3& Matrix3::operator*=(double scalar)
{
	(*this) = this->operator*(scalar);
	return (*this);
}

Matrix3& Matrix3::loadIdentity()
{
	(*this) = Matrix3();
	return (*this);
}

double Matrix3::det() const
{
	return (  m11*m22*m33
			- m11*m23*m32
			- m12*m21*m33
			+ m12*m23*m31
			+ m13*m21*m32
			- m13*m22*m31
			);
}

Matrix3 Matrix3::getInversed() const
{
	Matrix3 inv;
	inv.m11 = m22*m33-m23*m32;
	inv.m12 = m13*m32-m12*m33;
	inv.m13 = m12*m23-m13*m22;
	inv.m21 = m23*m31-m21*m33;
	inv.m22 = m11*m33-m13*m31;
	inv.m23 = m13*m21-m11*m23;
	inv.m31 = m21*m32-m22*m31;
	inv.m32 = m12*m31-m11*m32;
	inv.m33 = m11*m22-m12*m21;
	inv /= this->det();

	return inv;
}

Matrix3& Matrix3::inverse()
{
	return ((*this)=getInversed());
}

Matrix3 Matrix3::getTranspose() const
{
	Matrix3 tran;
	tran.m11 = m11;
	tran.m12 = m21;
	tran.m13 = m31;
	tran.m21 = m12;
	tran.m22 = m22;
	tran.m23 = m32;
	tran.m31 = m13;
	tran.m32 = m23;
	tran.m33 = m33;
	return tran;
}

Matrix3& Matrix3::transpose()
{
	return ((*this)=getTranspose());
}

Matrix3 Matrix3::identityMatrix()
{
	Matrix3 ret;
	ret.m11 = 1.0;
	ret.m22 = 1.0;
	ret.m33 = 1.0;
	return ret;
}

Matrix3 Matrix3::fromBasis(const Vector3& vect1,const Vector3& vect2,const Vector3& vect3)
{
	Matrix3 ret;
	ret.m11 = vect1.x; ret.m12 = vect2.x; ret.m13 = vect3.x;
	ret.m21 = vect1.y; ret.m22 = vect2.y; ret.m23 = vect3.y;
	ret.m31 = vect1.z; ret.m32 = vect2.z; ret.m33 = vect3.z;
	return ret;
}


