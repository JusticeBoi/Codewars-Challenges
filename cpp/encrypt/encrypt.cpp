#include <iostream>
#include <string>


std::string encrypt(std::string text, int rule);
int main()
{

//char a = '\0';
//a += 2;
//
//std::cout << a<<std::endl;

auto ans = encrypt("please encrypt me",2);
for(auto q : ans)
{
	std::cout << q;
}
std::cout << std::endl;
	return 0;
}

std::string encrypt(std::string text, int rule)
{

//	for(auto& a_char : text )
//		{
//			std::cout <<a_char << std::endl;
//			if ((int)a_char == 32)
//			{
//				std::cout << "inside "<<std::endl;
//				a_char =char(92);
//
//			}
//			std::cout <<a_char << std::endl;
//		}

	for(auto& a_char : text )
	{
		std::cout <<"a_char before : " <<a_char << std::endl;
		if((int)a_char!=92  )a_char += rule;
//		std::cout <<"a_char after : " <<a_char << std::endl;
	}


	return text;

}

