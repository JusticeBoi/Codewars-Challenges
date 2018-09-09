#include <iostream>
#include <algorithm>
#include <vector>

//namespace answer
//{
//	static int answer_counter =
//}
class Fibkind
{
public:

	static std::vector<int> functionN(int n)
	{
		std::vector<int> vector_n {1,1} ;

		for ( int i = 3 ; i <= n ;++i)
		{
			vector_n.push_back(vector_n[i -vector_n[i-2] -1 ] + vector_n[i -vector_n[i-3] -1 ] );

		}
		return vector_n;

	}

    static int lengthSupUK(int n, int k)
    {
    	std::vector<int> u_of_n = functionN(n);
    	int answer_counter = 0;
    	std::for_each(u_of_n.begin(),u_of_n.end(),[k,&answer_counter](int a)
    			{
    				if( a >= k) answer_counter++; return;
    			});


    	return answer_counter;

    }
    static int comp(int n)
    {
    	std::vector<int> u_of_n = functionN(n);
    	int answer_counter = 0;
    	for(auto it = u_of_n.begin()+1; it != u_of_n.end();it++)
    	{
    		if( *(it) < *(it-1) ) answer_counter++;
    	}
    	return answer_counter;
    }
};



int main()
{

std::cout <<Fibkind::lengthSupUK(3332,973) << std::endl;
std::cout << Fibkind::comp(200) << std::endl;
//auto ans = Fibkind::functionN(90000);
//
//for (auto& a : ans)
//{
//	std::cout << a << std::endl;
//}

	return 0;
}
