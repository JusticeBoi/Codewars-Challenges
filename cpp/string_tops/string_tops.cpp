#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using std::cout;
using std::endl;
std::vector<int> findNumberOfVerticalSpaces(std::string::size_type size_str)
{
std::vector<int> ans;


int start = 2;

for ( size_t i = 2 ; start <= size_str ; i += 2)
{
	ans.push_back(start);
	start += (2*i + 1);
}
return ans;
}

std::string tops(const std::string& msg)
{

	std::string real_answer ;
	auto m_size = msg.size();
	std::vector<size_t> ans;
	size_t start = 2;
	for ( size_t i = 2 ; start <= m_size ; i += 2)
	{
		ans.push_back(start);
		start += (2*i + 1);
	}

	for(auto a : ans)
	{
		real_answer.push_back(msg[a-1]);
	}
	std::reverse(real_answer.begin(),real_answer.end());

    return real_answer;
}

int main()
{

	auto ans = tops("abcdefghijklmnopqrstuvwxyz1236789ABCDEFGHIJKLMN");

	for(auto b : ans)
	{
		cout << b << endl;
	}



	return 0;
}
