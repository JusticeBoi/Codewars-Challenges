#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Kata
{
public:
    static std::vector<std::string> towerBuilderNew(int nFloors)
        {
    	std::string space((nFloors*2)-1,' ');
    	std::vector<std::string> ans;
    	int mid = (2*nFloors-1)/2 ;
    	for ( int i = 0;i < nFloors ; i++)
    	{
    		space[mid+i] = '*';
    		space[mid-i] = '*';
        	ans.push_back(space);
    	}

    	return ans;
        }


};

int main()
{
//	auto a = Kata::towerBuilder(6);
//
//	for(auto& a_star: a)
//	{
//		std::cout << a_star << std::endl;
//	}
	auto b = Kata::towerBuilderNew(30);
	int counter = 1;
	for (auto ch : b)
	{
		std::cout <<"floor: "<< counter++ <<"\t"<<  ch << std::endl;
	}



	return 0;
}
