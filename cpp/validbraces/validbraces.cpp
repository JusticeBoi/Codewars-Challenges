#include <iostream>
#include <algorithm>
#include <string>


bool valid_braces(std::string braces);
int main()
{
std::string qq {"([{}])"};

std::cout << valid_braces(qq) << std::endl;

	return 0;
}


bool valid_braces(std::string braces)
{
	auto ReplaceStringInPlace =[] (std::string& subject, std::string search,
	                          std::string replace) {
	    size_t pos = 0;
	    while ((pos = subject.find(search, pos)) != std::string::npos) {
	         subject.replace(pos, search.length(), replace);
	         pos += replace.length();
	    }
	};
	int counter = 0;
		while (braces.size() && counter < 100 )
		{
			ReplaceStringInPlace(braces,"()","");
			ReplaceStringInPlace(braces,"[]","");
			ReplaceStringInPlace(braces,"{}","");
			ReplaceStringInPlace(braces,"()","");
			counter++;
		}
	std::cout<<"size : " << braces.size() <<"\tcounter: " <<counter<<std::endl;


	std::cout << braces << std::endl;
	if(braces.size()) return 0;

	return 1;
}

//bool valid_braces(std::string braces)
//{
//	auto countBraces = [](std::string to_count)
//		{
//		int n_of_curly = 0;
//		int n_of_para = 0;
//		int n_of_brack = 0;
//		for ( auto a : to_count)
//		{
//			//std::cout << a << std::endl;
//			if(a == '(') n_of_para++;
//			else if (a == ')')  n_of_para--;
//			else if (a == '{')  n_of_curly++;
//			else if (a == '}')  n_of_curly--;
//			else if (a == '[')  n_of_brack++;
//			else if (a == ']')  n_of_brack--;
//		}
//		std::cout << "\t" << n_of_brack <<"\t" << n_of_para << "\t" << n_of_curly << std::endl;
//		if(n_of_brack || n_of_para || n_of_curly) return 0;
//		else return 1;
//		};
//
//	if(!countBraces(braces)) return 0;
//
//
//	int counter =-1;
//	for (auto it = braces.begin(); it != braces.end() ; it++)
//	{
//		counter++;
//		char a_bracket = *(it);
//
//		if (a_bracket == '(')
//		{
//			std::string sub_str = braces.substr(counter+1);
//			auto m_closer = sub_str.find_first_of(')');
//			std::cout <<"my location = " <<counter<<"\t"<<m_closer << std::endl;
//			std::string new_sub_str = sub_str.substr(0,m_closer);
//			std::cout <<"new sub str (: \t"<< new_sub_str << std::endl;
//			if(!countBraces(new_sub_str)) return 0;
//		}
//		else if (a_bracket == '[')
//		{
//			std::string sub_str = braces.substr(counter+1);
//			auto m_closer = sub_str.find_first_of(']');
//			std::cout <<"my location = " <<counter<<"\t"<<m_closer << std::endl;
//			std::string new_sub_str = sub_str.substr(0,m_closer);
//			std::cout <<"new sub str [: \t"<< new_sub_str << std::endl;
//			if(!countBraces(new_sub_str)) return 0;
//
//		}
//		else if (a_bracket == '{')
//		{
//			std::string sub_str = braces.substr(counter+1);
//			auto m_closer = sub_str.find_first_of('}');
//			std::cout <<"my location = " <<counter<<"\t"<<m_closer << std::endl;
//			std::string new_sub_str = sub_str.substr(0,m_closer);
//			std::cout <<"new sub str {: \t"<< new_sub_str << std::endl;
//			if(!countBraces(new_sub_str)) return 0;
//
//		}
//	}
//
//
//	return 1;
//}



