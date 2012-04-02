// problem10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <list>
#include <math.h>


unsigned int getPrime(unsigned int num)
{
	static std::vector<unsigned int> primeFactors;
	if(primeFactors.empty()) {		
		primeFactors.push_back(2);
		primeFactors.push_back(3);
	}
	primeFactors.reserve(num);

	if(primeFactors.size()>num) {
		return primeFactors[num-1];
	}

	unsigned int last = primeFactors.back();
	unsigned int Divided=last;	
	while (primeFactors.size() < num)
	{
		Divided+=2;
		bool isSimple=true;
		std::vector<unsigned int>::iterator it = primeFactors.begin()+1;
		unsigned int maxDivider = static_cast<unsigned int>(sqrt(Divided));
		for( it;  *it<=maxDivider ;  ++it)
		{
			if(Divided%*it == 0) {
				isSimple = false;
				break;
			}
		}
		if(isSimple) {
			primeFactors.push_back(Divided);			
		}
	}	
	return primeFactors[num-1];
}



using namespace boost::posix_time;

int _tmain(int argc, _TCHAR* argv[])
{
	ptime sTime = microsec_clock::local_time();
	std::cout<<"Start: "<< to_simple_string(sTime)<<std::endl;
	unsigned int prime(0);
	int64_t sum(0);
	unsigned int i(0);
	while ((prime = getPrime(++i))<2000000) {
		sum+=prime;
	}

	ptime eTime = microsec_clock::local_time();
	std::cout<<"End: "<< to_simple_string(eTime)<<std::endl;
	std::cout<<"Elapsed: "<< time_duration (eTime -  sTime) <<std::endl;	
	std::cout << "res = " << sum <<std::endl;	
	return 0;
}


