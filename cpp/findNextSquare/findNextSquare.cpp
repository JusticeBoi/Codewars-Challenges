#include <iostream>
#include <cmath>

long int findNextSquare(long int sq);
int main()
{

	std::cout <<findNextSquare(15241383936)<<std::endl;
	std::cout <<findNextSquare(101)<<std::endl;


	return 0;
}


long int findNextSquare(long int sq) {
	auto isPerfectSquare = [](long int parent)
			{
				double child = sqrt(parent);
				if (pow((int)child,2) == parent) return 1;
				else return 0;
			};

if(isPerfectSquare(sq)) return pow(sqrt(sq)+1,2);

  return -1;
}
