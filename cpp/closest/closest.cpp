#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <tuple>
#include <utility>
#include <cmath>
#include <algorithm>

#define DEBUG



namespace Closest
{
long long findWeight(const std::string& number)
{
	long long sum = 0;
	for (auto& a_digit : number)
	{
		sum += (int)a_digit - (int)'0';
	}
	return sum;
}

std::pair<std::vector<std::vector<long long>>,long long> findSmallestWeightDiff(const std::vector<std::vector<long long>>& info)
		{
	long long diff = 1000000;
	for(auto& tupl1 : info)
	{
		for(auto& tupl2 : info)
		{
			if(tupl1 != tupl2 && diff > abs(tupl1[0]-tupl2[0]) )
			{
				diff = abs(tupl1[0]-tupl2[0]);
			}
		}

	}
	std::vector<std::vector<long long>> ans; // ans contains

	for (auto& tupl1 : info)
	{
		for (auto& tupl2 : info)
		{
			//					std::cout << abs(tupl1[0]-tupl2[0]) << std::endl;
			if(abs(tupl1[0]-tupl2[0])==diff && tupl1 != tupl2 && std::find(ans.begin(),ans.end(),tupl1) == ans.end() )
			{
				//						std::cout << "in 1 tuple 1 strng " << tupl1[1]<<" tuple 2 strng " << tupl2[1] << std::endl;
				ans.push_back(tupl1);
			}
			if(abs(tupl1[0]-tupl2[0])==diff && tupl1 != tupl2 && std::find(ans.begin(),ans.end(),tupl2) == ans.end() )
			{
				//						std::cout << "in 2 " << std::endl;
				ans.push_back(tupl2);
			}

		}
	}
#ifdef DEBUG
	std::cout <<"ans with diff " <<diff <<std::endl;
	for(auto q : ans)
	{
		std::cout << "weight : " << q[0] << " number in strng : " << q[1] << " with index : " << q[2]<< std::endl;
	}
#endif


	return std::make_pair(ans,diff);
		}


std::vector<std::tuple<int, unsigned int, long long>> closest(const std::string &strng)
    				{
	if(strng == "") 		return { std::make_tuple(0,0,0), std::make_tuple(0,0,0) };
	std::vector<std::tuple<int, unsigned int, long long>> ans ;
	std::vector<std::vector<long long>> weights ;
	ans.emplace_back(std::make_tuple(1,1,1));
	std::istringstream iss (strng);
	std::string number = "";
	int counter = 0 ;
	while (iss >> number)
	{
		std::cout << number << std::endl;
		weights.push_back({findWeight(number),std::stoi(number),counter++});
	}
	std::cout <<std::endl;
#ifdef DEBUG
		for(auto q : weights)
		{
			std::cout << "weight : " << q[0] << " number in strng : " << q[1] << " with index : " << q[2]<< std::endl;
		}
#endif
	auto q = findSmallestWeightDiff(weights);
	if( q.first.size() == 2) // only two numbers have smallest weight, answer is found
	{
		if((q.first)[0][0] > (q.first)[1][0])
		{
			std::swap(q.first[0],q.first[1]);
		}
		#ifdef DEBUG
		std::cout << "size is 2 " <<std::endl;
		std::cout << "weight : " << q.first[0][0] << " number in strng : " << q.first[0][1] << " with index : " << q.first[0][2]<< std::endl;
		std::cout << "weight : " << q.first[1][0] << " number in strng : " << q.first[1][1] << " with index : " << q.first[1][2]<< std::endl;
		#endif
		return { std::make_tuple(q.first[0][0],q.first[0][2],q.first[0][1]), std::make_tuple(q.first[1][0],q.first[1][2],q.first[1][1]) };
		//		auto min = std::min_element(q.first.begin(),q.first.end());
		//		std::cout << *(min) << std::endl;
	}
	else
	{
//		std::cout<< " before sort : " << std::endl;
//		for( auto qq : q.first)
//		{
//			std::cout << "weight : " << qq[0] << " number in strng : " << qq[1] << " with index : " << qq[2]<< std::endl;
//
//		}
		//sort according to their weights, if the smallest two weights are different than each other, they are the answers
		std::sort(q.first.begin(), q.first.end(),[]
												  (std::vector<long long> a, std::vector<long long> b)
												  {
			return a[0] < b[0] ;
												  });
		#ifdef DEBUG
		std::cout<< " after sort : " << std::endl;
		for( auto qq : q.first)
		{
			std::cout << "weight : " << qq[0] << " number in strng : " << qq[1] << " with index : " << qq[2]<< std::endl;
		}
		#endif
		if(q.first[0][0]!=q.first[1][0]) //
		{
//			std::cout <<" q.first[0][0] : " << q.first[0][0] << " is not equal to q.first[1][0] : " << q.first[1][0] << std::endl;

			return { std::make_tuple(q.first[0][0],q.first[0][2],q.first[0][1]), std::make_tuple(q.first[1][0],q.first[1][2],q.first[1][1]) };
		}
		else // last condition, which is checking index
		{
			q.first.erase(std::remove_if(q.first.begin(),q.first.end(),[q]
																		(std::vector<long long> a)
																		{
				return a[0] != q.first[0][0];
																		}
			),q.first.end());



			std::sort(q.first.begin(), q.first.end(),[]
													  (std::vector<long long> a, std::vector<long long> b)
													  {
				return a[2] < b[2] ;
													  });

			#ifdef DEBUG
			std::cout << "after erase & sort  " << std::endl;
			for( auto qq : q.first)
			{
				std::cout << "weight : " << qq[0] << " number in strng : " << qq[1] << " with index : " << qq[2]<< std::endl;

			}
			#endif

			return { std::make_tuple(q.first[0][0],q.first[0][2],q.first[0][1]), std::make_tuple(q.first[1][0],q.first[1][2],q.first[1][1]) };


		}
	}
	return ans;
    				}
}


int main()
{
	std::vector<std::tuple<int, unsigned int, long long>> ans = { std::make_tuple(9,0,54), std::make_tuple(9,2,162) };
	auto ans_mi = Closest::closest("");

	int a = 125;

//	std::cout << a % 10 <<"  " <<(a/10) % 10 << std::endl;

	if (ans_mi == ans) std::cout << "yes" << std::endl;
//	Closest::findWeight("232323232323");


	return 0;
}
