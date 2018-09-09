#include <iostream>
#include <vector>
#include <algorithm>



std::vector<int> bubbleSortOnce(const std::vector<int> &input);
int main()
{

	bubbleSortOnce({ 9, 7, 5, 3, 1, 2, 4, 6, 8});



	return 0;
}


std::vector<int> bubbleSortOnce(const std::vector<int> &input)
				{

	std::vector<int> ans = input;


	for (auto it = ans.begin(); it!=(ans.end()-1);it++)
	{
		if(*(it) > *(std::next(it))) std::iter_swap(it,std::next(it));

	}

//	for(auto & a : ans) std::cout << a << std::endl;
	return ans;
				}
