// problem9.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <list>
#include <math.h>


// a bit of calcualtions 
//
//a^2 + b^2 = c^2 
//a+b+c=1000
//c = sqrt (a^2 + b^2)
//c = 1000 - (a+b)
//
//1000 - (a+b) = sqrt (a^2 + b^2)
//(1000 - (a+b))^2 =  = a^2 + b^2
//sqrt (a^2 + b^2) + a + b = 1000
//1000^2 -2 *1000 *(a+b) + (a+b)^2 = a^2 + b^2
//1000^2 - 2000(a+b) + (a^2 +2ab +b^2) - a^2 - b^2 =0
//1000^2 -2000(a+b) + 2ab = 0
//1000^2 -2000a - 2000b + 2ab =0
//- 2000a -2000b +2ab   = - 1000^2 
//2000a -2ab = 1000^2 - 2000b
//2000 - 2b = (1000^2 - 2000b)/a
//- 2b = (1000^2 - 2000b)/a -2000
//2b = 2000 - (1000^2 - 2000b)/a
//b =  1000 - (1000*500 - 1000b)/a
//b = 1000 (1 - (500 - b)/a)
//b = 1000  - 1000*500/a + 1000b/a
//b - 1000 b/a  = 1000 - 1000*500/a
//ba - 1000b = 1000a - 1000*500
//b(a-1000) = 1000a-1000*500
//b = 1000(500-a) / (1000-a)


//it's needed to find the first natural number that results from the formula
using namespace boost::posix_time;

int _tmain(int argc, _TCHAR* argv[])
{
	ptime sTime = microsec_clock::local_time();
	std::cout<<"Start: "<< to_simple_string(sTime)<<std::endl;
	unsigned int result = 0;	
	for (unsigned int a=1; a<998; ++a)
	{
		double b = 1000.0*(500.0-a) / (1000.0-a);
		unsigned int b_ = static_cast<int>(b);
		if((double)b_ == b ) //is narural?
		{			
			result = a*b*(1000-a-b);
			break;
		}
		
	}	
	ptime eTime = microsec_clock::local_time();
	std::cout<<"End: "<< to_simple_string(eTime)<<std::endl;
	std::cout<<"Elapsed: "<< time_duration (eTime -  sTime) <<std::endl;	
	std::cout << "res = " << result <<std::endl;	
	return 0;
}