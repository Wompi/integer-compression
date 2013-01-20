/*
 *  RandomGenerator.h
 *  integer-compression
 *
 *  Created by Robert Schott on 1/20/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef RANDOM_GENERTOR
#define RANDOM_GENERTOR


#include "MyTypes.h"

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/variate_generator.hpp>

#include <boost/random/uniform_int_distribution.hpp>
#include <vector>

namespace wompi 
{

class RandomGenerator
{	
public:
	typedef boost::random::mt19937 Engine;
	typedef boost::random::uniform_int_distribution<int> Distributor;
	typedef boost::random::variate_generator<Engine,Distributor> Generator;
		
	
	RandomGenerator(int min,int max);
	~RandomGenerator();
	
	unsigned int getRandomNumber();
	Vector getRandomVector(unsigned int const size);

private:
	Engine engine;
	Distributor distributor;
	Generator generator;
};

}
#endif

