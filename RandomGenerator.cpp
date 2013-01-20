/*
 *  RandomGenerator.cpp
 *  integer-compression
 *
 *  Created by Robert Schott on 1/20/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "RandomGenerator.h"
#include <iostream>

namespace wompi 
{

RandomGenerator::RandomGenerator(int min, int max) : engine() , distributor(min,max), generator(engine,distributor)
{
	using namespace std;
	cout << "Constructor" << endl;	
}

RandomGenerator::~RandomGenerator()
{
	using namespace std;	
	cout << "Deconstructor" << endl;
}

unsigned int RandomGenerator::getRandomNumber()
{
	return generator();
}

Vector RandomGenerator::getRandomVector(unsigned int const size)
{
	Vector v;
	for (int i=0; i<size; i++) 
	{
		v.push_back(generator());
	}
	return v;
}

}
