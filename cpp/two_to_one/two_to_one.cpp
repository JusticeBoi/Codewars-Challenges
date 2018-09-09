#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//int main()
//{
//    std::string str1 = "Text with some   spaces";
//    str1.erase(std::remove(str1.begin(), str1.end(), ' '),
//               str1.end());
//    std::cout << str1 << '\n';
//
//    std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
//    str2.erase(std::remove_if(str2.begin(),
//                              str2.end(),
//                              [](unsigned char x){return std::isspace(x);}),
//               str2.end());
//    std::cout << str2 << '\n';
//}



class TwoToOne
{
public:
    static std::string longest(const std::string &s1, const std::string &s2)
    {

    	std::string total = s1 + s2;
    	std::sort(total.begin(),total.end());
//    	std::cout << total << std::endl;
    	for(auto it = total.begin();it != total.end();it++)
    	{
    		if( *(it) == *(it+1)  )
    		{
    			*(it) = '\0';

    		}
    	}
    	total.erase(std::remove(total.begin(),total.end(),'\0'),total.end());
    	return total;
    };

};

int main()
{
std::string ans = TwoToOne::longest("aretheyhere","yestheyarehere");

for (auto& b : ans)
{
	std::cout << b << std::endl;
}

	return 0;
}
