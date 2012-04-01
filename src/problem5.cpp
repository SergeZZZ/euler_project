// problem5.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <list>
#include <math.h>


#include "stdafx.h"




void addDividers(int num, std::map<int64_t,int64_t> &map);


int64_t getPrime(unsigned int num)
{
	static std::vector<int64_t> primeFactors;
	if(primeFactors.empty()) {
		primeFactors.push_back(1);
		primeFactors.push_back(2);
		primeFactors.push_back(3);
	}

	if(primeFactors.size()>num) {
		return primeFactors[num-1];
	}

	int64_t last = primeFactors.back();
	int64_t Divided=last;
	std::vector<int64_t>::iterator beginIteraton = primeFactors.begin()+2;
	while (primeFactors.size() < num)
	{
		Divided+=2;
		bool isSimple=true;
		std::vector<int64_t>::iterator it = beginIteraton; 
		for( it;  *it<=static_cast<int64_t>(sqrt(Divided)) && it!= primeFactors.end() ;  ++it)
		{
			if(Divided%* it == 0) {
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


void replaceInMap( int64_t key, int64_t num, std::map<int64_t,int64_t> &map )
{
	if(map.find(key)==map.end() || map[key] < num)
	{			
		map[key]=num;
	}
}

void findDividers(int num, std::map<int64_t,int64_t> &map)
{
	std::map<int64_t,int64_t> localMap;
	addDividers(num, localMap);
	std::map<int64_t,int64_t>::iterator iter = localMap.begin();
	for(iter; iter!= localMap.end(); ++iter) 
	{		
		replaceInMap(iter->first, localMap[iter->first], map);
	}
}


void appendToMap(int64_t key, std::map<int64_t,int64_t> &map)
{
	if(map.find(key)!=map.end()) 
		map[key] = map[key] + 1;
	else 
		map[key] = 1;

}


void addDividers(int num, std::map<int64_t,int64_t> &map)
{	
	int64_t prime = 1;
	bool foundOne(false);
	int64_t lastPart = num;
	for(int i=2; prime<=static_cast<int64_t>(sqrt(lastPart));++i)
	{		
		prime = getPrime(i);		
		while (lastPart%prime == 0 ) {
			appendToMap(prime, map);
			lastPart=lastPart/prime;
			foundOne = true;
		}
	}
	if(!foundOne) {
		appendToMap(num, map);
	}
}


using namespace boost::posix_time;

int _tmain(int argc, _TCHAR* argv[])
{
	ptime sTime = microsec_clock::local_time();
	std::cout<<"Start: "<< to_simple_string(sTime)<<std::endl;
	unsigned int  num = 20;	
	int64_t result (1);
	std::map<int64_t,int64_t> dividers;
	for (unsigned int i = 2; i<=20; i++) 
	{
		findDividers(i, dividers);
	}
	std::map<int64_t,int64_t>::iterator iter = dividers.begin();
	for(iter; iter!= dividers.end(); ++iter) 
	{
		result = result * static_cast<int64_t>(pow ( iter->first, iter->second));
	}
	ptime eTime = microsec_clock::local_time();
	std::cout<<"End: "<< to_simple_string(eTime)<<std::endl;
	std::cout<<"Elapsed: "<< time_duration (eTime -  sTime) <<std::endl;	
	std::cout << "res = " << result <<std::endl;	
	return 0;
}

