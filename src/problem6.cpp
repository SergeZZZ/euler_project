// problem6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <list>
#include <math.h>


using namespace boost::posix_time;
int _tmain(int argc, _TCHAR* argv[])
{
	ptime sTime = microsec_clock::local_time();
	std::cout<<"Start: "<< to_simple_string(sTime)<<std::endl;

	int64_t sumOfSq(0);
	int64_t sum(0);	
	for (unsigned int i = 1; i<=100; i++)
	{
		sumOfSq = sumOfSq+static_cast<int64_t>(pow(i,2));
		sum=sum+i;
	}
	int64_t sqOfSumm = static_cast<int64_t>(pow(sum,2));
	int64_t result = sqOfSumm - sumOfSq;
	
	ptime eTime = microsec_clock::local_time();
	std::cout<<"End: "<< to_simple_string(eTime)<<std::endl;
	std::cout<<"Elapsed: "<< time_duration (eTime -  sTime) <<std::endl;	

	std::cout << "res = " << result <<std::endl;	
	return 0;
	
}

