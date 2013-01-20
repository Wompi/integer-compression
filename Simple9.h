/*
 *  Simple9.h
 *  integer-compression
 *
 *  Created by Robert Schott on 1/20/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SIMPLE_NINE
#define SIMPLE_NINE

#include "MyTypes.h"

namespace wompi 
{
class Simple9
{
public:
	Simple9();
	~Simple9();
	
	void encode(Vector &vin, Vector &vout);

private:	
	bool check(int sum, int index,int bits);
};

}
#endif 