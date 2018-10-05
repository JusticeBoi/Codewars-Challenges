#include <iostream>
#include <string>
#include <cmath>
class DigPow
{
public:
  static int digPow(int n, int p);
};



int DigPow::digPow(int n,int p)
{
	std::string s_n = std::to_string(n);
	int tmp = 0;
	int power = p;
	int sum_with_p_power = 0;
	for(auto _char : s_n)
	{
		tmp = _char - '0';
		sum_with_p_power += pow(tmp,power++);
	}
	double sum_double  = static_cast<double>(sum_with_p_power);
	double n_double = static_cast<double>(n);
	if (std::floor(sum_double/n_double) == std::ceil(sum_double/n_double) ) return sum_with_p_power / n;
	else return -1;
}


int main()
{

	double n = 46288;

std::cout <<DigPow::digPow(n,3)<<std::endl;
	return 0;
}
