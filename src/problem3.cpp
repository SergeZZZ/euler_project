#include <iostream>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <list>


bool testIfSimple(int64_t num);
using namespace boost::posix_time;

int main()
{  
	ptime sTime = microsec_clock::local_time();
	std::cout<<"Start: "<< to_simple_string(sTime)<<std::endl;

	int64_t bignum = 600851475143;		
	int64_t sqrtnum =  static_cast<int64_t>(sqrt(bignum));
	int64_t max(1);
	int inc =1;
	for (int64_t i = 2; i<=sqrtnum; i++) 
	{		
			if(bignum%i) continue;	
			if (testIfSimple(i)) max = i;
			if(i%2==1) inc = 2; //in case it's odd, increment by 2 to skip even numbers
	}
	if(max == 1) max = bignum;
	ptime eTime = microsec_clock::local_time();
	std::cout<<"End: "<< to_simple_string(eTime)<<std::endl;
	std::cout<<"Elapsed: "<< time_duration (eTime -  sTime) <<std::endl;

	std::cout << "max = " << max <<std::endl;	
}
bool testIfSimple(int64_t num)
{
	static std::list<int64_t> primeFactors;	
	int64_t i = 2;
	int64_t sqrtnum = static_cast<int64_t>(sqrt(num));
	if(!primeFactors.empty()) {
		std::list<int64_t>::iterator it = primeFactors.begin();
		for(it; it != primeFactors.end(); ++it)
		{
			if(*it > sqrtnum ) {				
				return true;
			}
			if(num%*it == 0) {						
				return false;
			}
		}
		i = primeFactors.back()+2;
	}
	
	int inc = 1;
	for (i; i<=sqrtnum; i=i+inc)
	{
		if(num%i == 0) {			
			return false;
		}
		if(testIfSimple(i)) primeFactors.push_back(i);
		if(i%2==1) inc =2; //in case it's odd, increment by 2 to skip even numbers
	}	
	return true;
}
//4613732