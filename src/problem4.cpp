// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "boost/lexical_cast.hpp"
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

bool isPalindromic(unsigned int number)
{
	std::string num = boost::lexical_cast<std::string>(number);
	int i=0,r=num.length()-1;
	bool palindromic(true);
	for(int i = 0; i<r; ++i,--r)
	{
		if(num.at(i)!=num.at(r)) {
			palindromic = false;
			break;
		}
	}
	return palindromic;

}

int _tmain(int argc, _TCHAR* argv[])
{
	ptime sTime = microsec_clock::local_time();
	std::cout<<"Start: "<< to_simple_string(sTime)<<std::endl;
	unsigned int num1=999, num2;
	unsigned int theNum=0; //searching for	
	unsigned int newNum (0); //current  pair result
	unsigned int minNum = 100;
	for(num1; num1>=minNum ;--num1)
	{
		for(num2=999; num2>=minNum && (newNum = num1*num2) > theNum; --num2)
		{			
			if(isPalindromic( newNum ))  
			{				
				theNum=newNum;				
				minNum = num2;
			}
		}
	}
	ptime eTime = microsec_clock::local_time();
	std::cout<<"End: "<< to_simple_string(eTime)<<std::endl;
	std::cout<<"Elapsed: "<< time_duration (eTime -  sTime) <<std::endl;
	std::cout << "number is:" <<theNum << std::endl; 
	return 0;
}

