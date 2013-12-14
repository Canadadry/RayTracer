/*
 * ToStdString.h
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

#ifndef TOSTDSTRING_H_
#define TOSTDSTRING_H_

#include <sstream>
#include <string>
#include <iomanip>

template <typename T> std::string tostr(const T& t)
{
	std::ostringstream os;
	os << std::setiosflags(std::ios::fixed) << std::setprecision(2)<< std::showpos;
	os<<t;
	return os.str();
}


#endif /* TOSTDSTRING_H_ */
