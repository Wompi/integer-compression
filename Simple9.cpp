/*
 *  Simple9.cpp
 *  integer-compression
 *
 *  Created by Robert Schott on 1/20/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "Simple9.h"
#include <iostream>
#include <math.h>

namespace wompi 
{

Simple9::Simple9()
{

}

Simple9::~Simple9()
{

}

void
Simple9::encode(Vector &vin, Vector &vout)
{
	
	int len = vin.size();
	
	// xxxx xxxxxxxx xxxxxxxxxx xxxxxxxxxx (key(4) ) (encode bits (28))
	
	int count = 1;
	int bitsum = 0;
	int maxl = 0;
	
	int l0 = int(log2(vin[0])); 
	maxl = (l0 > maxl) ? l0 : maxl;
	bitsum = maxl * count++;
	if (check(bitsum, 0,l0))
	{
		maxl = 0;
		bitsum = 0;
		count = 1;
	}
	
	int l1 = int(log2(vin[1])); 
	maxl = (l1 > maxl) ? l1 : maxl;
	bitsum = maxl * count++;
	if (check(bitsum, 1,l1))
	{
		maxl = 0;
		bitsum = 0;
		count = 1;
	}
	
	int l2 = int(log2(vin[2]));
	maxl = (l2 > maxl) ? l2 : maxl;
	bitsum = maxl * count++;
	if (check(bitsum, 2,l2))
	{
		maxl = 0;
		bitsum = 0;
		count = 1;
	}
	

	int l3 = int(log2(vin[3]));
	maxl = (l3 > maxl) ? l3 : maxl;
	bitsum = maxl * count++;
	if (check(bitsum, 3,l3))
	{
		maxl = 0;
		bitsum = 0;
		count = 1;
	}
	
	int l4 = int(log2(vin[4]));
	maxl = (l4 > maxl) ? l4 : maxl;
	bitsum = maxl * count++;
	if (check(bitsum, 4,l4))
	{
		maxl = 0;
		bitsum = 0;
		count = 1;
	}
	
	int l5 = int(log2(vin[5]));
	maxl = (l5 > maxl) ? l5 : maxl;
	bitsum = maxl * count++;
	if (check(bitsum, 5,l5))
	{
		maxl = 0;
		bitsum = 0;
		count = 1;
	}
	

}
	
bool
Simple9::check(int sum, int index, int bits)
{
	using std::cout;
	using std::endl;

	if (sum >= 28) 
	{
		cout << "i" << index << ": "<< sum << "bits: " << bits << " full " << endl; 
		return true;
	}
	cout << "i" << index << ": "<< sum << "bits: " << bits << " open " << endl; 
	return false;
}

}