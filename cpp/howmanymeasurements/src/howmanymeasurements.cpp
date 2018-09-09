#include <iostream>
#include <limits>
#include <vector>
#include <chrono>
#include <cmath>

// x ? y : z
// if(x) y else z
//


//unsigned int factorize(const unsigned int& a);
//unsigned int howManyMeasurements  (unsigned int n);
//unsigned int howManyMeasurementsOpti  (unsigned int n);
unsigned int howManyMeasurements  (unsigned int n);

int main()
{

for(int i = 1 ; i < 300 ; i++)
{
	std::cout << "i : " << i << " howManyMeasurements(i) : " <<howManyMeasurements(i) <<std::endl;
}
//	auto start_read = std::chrono::steady_clock::now();
//	for (unsigned int i = 1 ; i < 2132277304 ; i++)
//	{
//		factorize(i);
//	}
//	auto end_read = std::chrono::steady_clock::now();
//	auto diff_read = end_read - start_read;
//	std::cout <<"duration of factorize "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;

//std::cout << "i : " << 1135086032 << " howManyMeasurements(i) : " <<howManyMeasurementsOpti(1135086032) <<std::endl;


	return 0;
}
//unsigned int howManyMeasurements  (unsigned int n)
//{
////	std::cout << "n: "<<n<< std::endl;
//	if(n == 1) return 0;
//	else if(n == 2) return 1;
//	else
//	{
////		unsigned int a = howManyMeasurements((n/3));
////		unsigned int b =howManyMeasurements((n/3)+(n % 3));m
////		return (a >= b) ? a +1 : b+1 ;
//		return howManyMeasurements(factorize(n)) +1;
//	}
//	return 0;
//}
//unsigned int howManyMeasurementsOpti  (unsigned int n)
//{
////	std::cout << "n: "<<n<< std::endl;
//	if(n == 1) return 0;
//	else if(n == 2) return 1;
//	else
//	{
//		std::vector<unsigned int> vec = {0,1};
//
//		for (unsigned int i  = 3 ; i <=n ; i++)
//		{
//			vec.emplace_back(vec[factorize(i)-1]+1);
//		}
//		return vec[n-1];
//	}
//}
unsigned int howManyMeasurements  (unsigned int n)
{
	unsigned int a = 1;
	unsigned int ans = 0;

	for(unsigned int i = 0 ; i < 30 ;i++)
	{
		a += (2*pow(3,i));
		if( n <= a)
			{
				ans = i;
				break;
			}
	}
	return ans+1;
}
//unsigned int factorize(const unsigned int& n)
//{
//	if(!(n % 3)) return n/3;
//	else return (n/3)+1 ;
//}

