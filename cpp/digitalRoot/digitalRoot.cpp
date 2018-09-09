#include <iostream>
#include <string>
#include <memory>


int digital_root(int n);
int main()
{
	int b = digital_root(444);
	std:: cout << b << std::endl;


	return 0;
}

int digital_root(int n)
{
std::string a = std::to_string(n);
int sum = 0;

for (auto& c : a)
{
	int digit = (int)c -'0';
	if(digit < 0 && digit > 9 ) std::cerr << "something is not right" << std::endl;
	sum += digit;
}
if ( sum >= 10) return digital_root(sum) ;
else if( sum < 10) return sum;

return 0;
}
