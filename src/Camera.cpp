/*
 * Camera.cpp
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

#include "Camera.h"
#include "Matrix4.h"

Camera::Camera(const Point3& position,const Vector3& eyeDirection, const Vector3& up, double fovx)
: m_position(position)
, m_eyeDirection(eyeDirection)
, m_fovx(fovx)
, m_up(up)
{}

Camera::Camera(const Point3& position,const Point3&  eyePosition , const Vector3& up, double fovx)
: m_position(position)
, m_eyeDirection(eyePosition-position)
, m_fovx(fovx)
, m_up(up)
{}

Camera::Camera(const Camera& camera)
: m_position(camera.m_position)
, m_eyeDirection(camera.m_eyeDirection)
, m_fovx(camera.m_fovx)
, m_up(camera.m_up)
{}

Camera& Camera::operator=(const Camera& camera)
{
	m_position     = camera.m_position;
	m_eyeDirection = camera.m_eyeDirection;
	m_fovx         = camera.m_fovx;

	return (*this);
}

const Point3& Camera::getPosition() const
{
	return m_position;
}

void Camera::populateRayListToCast(std::vector<Vector3>& rayList, int column, int row) const
{
	rayList.clear();

	double ratio = (double)column/(double)row;

	Vector3 left = m_up.crossProduct(m_eyeDirection);
	left.normalise();
	Vector3 up = m_eyeDirection.crossProduct(left);
	up.normalise();

	Vector3 ray;
	Matrix4 v_rotation,rotation;
	rotation.loadIdentity();
	for(double j = 0; j<row ; j++) //vertical
	{
		double v_rot = j*m_fovx/ratio/(row-1)-m_fovx/ratio/2.0;
		v_rotation = Matrix4::rotationMatrix(v_rot,left);
		ray = v_rotation*m_eyeDirection;

		for(double i = 0; i<column ; i++) // horizontal
		{
			double h_rot = i*m_fovx/(column-1)-m_fovx/2.0;
			rotation = v_rotation*Matrix4::rotationMatrix(h_rot,up);
			ray = rotation*m_eyeDirection;
			rayList.push_back(ray);
		}
	}
}
