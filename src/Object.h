/*
 * Object.h
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

#ifndef OBJECT_H_
#define OBJECT_H_

#include "Vector3.h"
#include "Point3.h"
#include "Color.h"

class Object
{
public:
	Object();
	virtual ~Object();
	virtual bool instersect(const Vector3& vect, const Point3& fromPoint) =0;
	virtual Color computeColorAtPoint(const Point3& point) =0;
	Point3 lastIntersectionPoint;
};

#endif /* OBJECT_H_ */