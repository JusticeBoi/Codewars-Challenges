#include <iostream>
#include <inttypes.h>
#include <cmath>
#include <limits>
#include <iomanip>
#include <float.h>

namespace Suite
{

long double special_multiply(long double number, long double loc)
{
	long double ans = 1;
	for (long double i = 0 ; i < number-loc; i++)
	{
		ans *= (number -i);
	}
return ans;
}

 long double factorial(uint_fast64_t n)
{
	if(n==1) return 1;

	return n*factorial(n-1);


}
double going(uint_fast64_t n)
  {

	if(n < 1100)
	{
			long double lhs = 1.0 / factorial(n);
			long double rhs = 0;
		for (uint_fast64_t i = n; i > 0 ;i--)
			{
				rhs += factorial(i);
			}
			std::cout << "lhs : " << lhs << " rhs : " << rhs << std::endl;
			;
			return std::floor((lhs*rhs)*1000000) / 1000000 ;
	}
	else
	{
		long double ans = 0;

		for(long double i = 1; i  < n ; i++)
		{
			ans += (1.0/special_multiply(n,i));
			std::cout << "ans : " << ans << std::endl;
		}
		return std::floor((1.0 +ans) * 1000000)/1000000;

	}

  }
};


int main()
{

//	std::cout << Suite::factorial(5) << std::endl;
	std::cout <<std::setprecision(10) << Suite::going(10110) << std::endl;
//std::cout << Suite::special_multiply(5,1) << std::endl;

	return 0;
}
