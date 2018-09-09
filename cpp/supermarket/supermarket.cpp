#include <iostream>
#include <algorithm>
#include <numeric>


long queueTime(std::vector<int> customers,int n){

	size_t customer_size = customers.size();
	if (n == 1) return std::accumulate(customers.begin(),customers.end(),0);
	if( n >= customers.size()) return *(std::max_element(customers.begin(),customers.end()));
	std::vector<int> counter(customers.begin(),customers.begin()+n);
	int min = 0;
	int total_time = 0;
	do
	{
		if(n == customer_size)
			{
			min = *(std::max_element(counter.begin(),counter.end()));
			total_time +=min;
			break;
			}
		min = *(std::min_element(counter.begin(),counter.end()));
		total_time +=min;
		std::cout << "total time is : " << total_time << std::endl;

		for(auto& number : counter)
		{
			number -=min;
			if(!number && n < customer_size)
			{
				number = customers[n++];
			}
		}

	} while(n <= customer_size);
	return total_time;
}
int main()
{

	std:: cout <<queueTime(std::vector<int>{2,2,3,3,4,4}, 2) << std::endl;


	return 0;
}
