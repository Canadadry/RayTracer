/*
 * Camera.h
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

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Point3.h"
#include "Vector3.h"
#include <vector>

class Camera
{
public:
	Camera(const Point3& position,const Vector3& eyeDirection, const Vector3& up = Vector3(1,0,0),double fovx = 70.0);
	Camera(const Point3& position,const Point3&  eyePosition , const Vector3& up = Vector3(1,0,0),double fovx = 70.0);
	Camera(const Camera& camera);
	Camera& operator=(const Camera& camera);

	const Point3& getPosition() const;

	void populateRayListToCast(std::vector<Vector3>& rayList, int column, int row) const;

private:
	Point3  m_position;
	Vector3 m_eyeDirection;
	double  m_fovx;
	const Vector3 m_up;
};

#endif /* CAMERA_H_ */
