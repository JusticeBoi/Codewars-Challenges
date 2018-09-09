#include <iostream>
#include <vector>
#include <algorithm>


int find_even_index (const std::vector <int> numbers);
int main()
{
	 std::vector <int> numbers { 1,2,3,4,3,2,1 };
	 std::vector <int> numbers2 { 1,100,50,-51,1,1 };
	 std::vector <int> numbers3 { } ;
	 std::cout <<std::accumulate(numbers.end(),numbers.end(),0)<<std::endl;
//	 std::cout << find_even_index(numbers) << " , "<<find_even_index(numbers2)<<" , " <<find_even_index(numbers3)<<std::endl;


	return 0;
}
int find_even_index (const std::vector <int> numbers) {
	for(auto& n : numbers) std::cout << n << " , ";
	std::cout<<std::endl;
	if (numbers.size() == 0 && numbers.size()== 1) return 0;
	int tmp_sum_right = 0;
	int tmp_sum_left = 0;

	for (size_t i = 1 ; i < numbers.size() ; i++)
	{
		tmp_sum_right = std::accumulate(numbers.begin()+i,numbers.end(),0);
		tmp_sum_left = std::accumulate(numbers.begin(),numbers.begin()+i-1,0);
		if (tmp_sum_right == tmp_sum_left) return i-1;
	}
	return -1;
}
