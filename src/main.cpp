/*
 * main.cpp
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

#include <cstdio>
#include "Runtime.h"
#include "ext/tinyxml/tinyxml.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	if(argc != 2 )
	{
		printf("usage : Raytracer config.xml\n");
		return 0;
	}

	TiXmlDocument doc(argv[1]);
	if(!doc.LoadFile())
	//FILE* fp = fopen(argv[1],"r");
	//if(fp == NULL)
	{
		printf("RayTracer couldn't open file : %s\n", argv[1]);
		return 0;
	}

	//Runtime runtime;
	//runtime.readConfigFile(argv[1]);

	return 1;

//	Image out;
//	out.create(200,200);
//
//	Camera cam1(Point3(0, 0, 0),Point3(0,0,15));
//	Camera cam2(Point3(0,10.6,4.4),Point3(0,0,15));
//	Camera cam3(Point3(0,15,15),Point3(0,0,15));
//
//	RayTracer myRayTracer;
//	myRayTracer.setBackgroundColor(Color::yellow);
//	myRayTracer.addObject(new Triangle(Point3(2,0,12.2),Point3(12,0,12.2),Point3(2,10,12.2),Color::blue));
//	myRayTracer.addObject(new Sphere(Point3(-2,0,15),5,Color::red));
//	myRayTracer.addObject(new Sphere(Point3(2,0,15),5,Color::green));
//
//	myRayTracer.render(cam1,out);
//	out.saveAs("test1.png");
//	myRayTracer.render(cam2,out);
//	out.saveAs("test2.png");
//	myRayTracer.render(cam3,out);
//	out.saveAs("test3.png");
}
