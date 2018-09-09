#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

long long int maxNumber (long long int  number);

int main()
{


	int a = 1987582342;

	std::cout <<maxNumber(a) << std::endl;
	return 0;
}
long long int maxNumber (long long int  number)
{
	std::string str_rep = std::to_string(number);
	std::sort(str_rep.begin(),str_rep.end());
	std::reverse(str_rep.begin(),str_rep.end());
    return std::stoll(str_rep);
}
