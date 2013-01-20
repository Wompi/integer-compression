#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>

#include <math.h>

#include "RandomGenerator.h"
#include "Simple9.h"


int func_xor(unsigned int &a,unsigned int &b);


int main (int argc, char * const argv[]) 
{
	using std::cout;
	using std::endl;
	using std::stringstream;
	using std::ostream_iterator;
	using wompi::Vector;
	using wompi::RandomGenerator;
	using wompi::Simple9;
	
	unsigned short a = -1;
	
	cout << "uint=" << a << "size=" << sizeof(a)  << endl;
	
	RandomGenerator rg(20000,23000);

	Vector v = rg.getRandomVector(10);

	cout << "Values: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
	cout << endl;
	

	adjacent_difference(v.begin(), v.end(), v.begin(),func_xor);	
	cout << "Diff: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
	cout << endl;
	
	for (int i = 1; i <= 28; i++ )
	{
		int mod = 28 % i;
		cout << "MOD[" << i << "]: " << mod << endl;
	}
	
	Vector o;
	
	Simple9 s;
	s.encode(v,o);
	
	
	
//	for(int i=0;i<256;i++)
//	{
//		cout << "[" << i << "] = " << static_cast<unsigned int>(log2(i));
//		x = i;
//		r = 0;
//		while (x   >>= 1) // unroll for more speed...
//		{
//			r++;
//		}
//		
//		cout << " r=" << r << endl;
//	}
	
	
	
	
	return 0;
}

int func_xor(unsigned int &a,unsigned int &b)
{
	return a ^ b;
}
