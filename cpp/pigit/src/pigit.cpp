#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

std::string pig_it(std::string str);
bool str_isPunc(std::string);
int number_of_spaces(const std::string& str, const std::string& word);


int main()
{

std::string m_string {"O tempora o mores !" };
std::istringstream iss(m_string);
std::string word;
iss >> word;
std::cout << number_of_spaces(m_string,word)<<" word : "<<word<<std::endl;
iss >> word;
std::cout << number_of_spaces(m_string,word)<<" word : "<<word<<std::endl;
iss >> word;
std::cout << number_of_spaces(m_string,word)<<" word : "<<word<<std::endl;
iss >> word;
std::cout << number_of_spaces(m_string,word)<<" word : "<<word<<std::endl;

//std::cout<<pig_it("O tempora o mores !")<<std::endl;


	return 0;
}

int number_of_spaces(const std::string& str, const std::string& word)
{
int ans = 0;
size_t pos = str.find(word);
std::string new_str = str.substr(pos+word.size(),str.size());
std::cout << new_str << std::endl;
if(!new_str.size()) return 0;
else
{
	for (auto& c :new_str)
	{
		if (isspace(c)) ans++;
		else break;

	}
}
return ans;
}

bool is_there_double_space(const std::string& str)
{
	for(auto it = str.begin();it !=str.end() ; it++)
	{
		if (isspace(*(it)) && isspace(*(it+1))) return true;

	}
	return false;
}


std::string pig_it(std::string str)
{
	std::cout << str << std::endl;
	bool is_double_space = is_there_double_space(str);
	if(is_double_space) std::cout <<"double space " <<std::endl;
	std::istringstream iss(str);
	std::string a_word ;
	std::string ans;
	if (isspace(str[0]))
		{
			ans.append(1,' ');
			if (isspace(str[1]))
				{
					ans.append(1,' ');
				}
		}
	int number_of_space = 0;
	auto str_isPunc = [](const std::string str)
		{
		for (auto& a : str)
		{
			if (ispunct(a)) return true;
		}
		return false;
		};
	while(iss >> a_word)
	{
		number_of_space = number_of_spaces(str,a_word);

		if(str_isPunc(a_word))
			{
			std::cout <<"punc "<<a_word <<std::endl;
			ans.append(a_word);
			continue;
			}
		if(a_word.size() > 1)
		{
			std::cout << a_word << std::endl;
			a_word.append(1,a_word[0]);
			a_word.erase(0,1);
		}
		a_word+="ay";
		if (number_of_space) a_word.append(number_of_space,' ');
		ans.append(a_word);
	}
	if(isspace(*(ans.end()-1))) ans.pop_back();
		return ans;
}



//std::string pig_it(std::string str)
//{
////	auto ReplaceStringInPlace =[] (std::string& subject, std::string search,
////		                          std::string replace) {
////		    size_t pos = 0;
////		    while ((pos = subject.find(search, pos)) != std::string::npos) {
////		         subject.replace(pos, search.length(), replace);
////		         pos += replace.length();
////		    }
////		};
//
//	std::string word;
//	std::string ans;
//
//	for(auto& a_char : str)
//	{
//		if(isalpha(a_char))
//		{
//			std::cout << "alpha " <<a_char <<std::endl;
//			word.append(1,a_char);
//			continue;
//		}
//		else if (ispunct(a_char))
//		{
//			std::cout <<"char is punc " << std::endl;
//			word.append(1,a_char);
//			if(word.size()==1)
//			{
//				ans.append(word);
//				continue;
//			}
//		}
//		std::cout << "word : " << word << std::endl;
//		if (word.size())
//		{
//			word.append(1,word[0]);
//			word.erase(0,1);
//			word+="ay";
//			ans.append(word);
//			word.clear();
//		}
//		word.clear();
//		if (isspace(a_char))
//		{
//			ans.append(1,a_char);
//		}
//	}
//	return ans;
//}

//	for (auto it = str.begin();it != str.end();it++)
//	{
//		if (!isspace((*it)))
//		{
//			if(ispunct(*(it)))
//			{
//				ans.append(1,*(it));
//			}
//			else word.append(1,*(it));
//			continue;
//		}
//		if(word.size())
//		{
//			word.append(1,word[0]);
//			word.erase(0,1);
//			word+="ay";
//			ans.append(word);
//			word.clear();
//
//		}
//
//		if(isspace((*(it+1))) && !isspace((*(it+2))) )
//		{
//			ans.append(2,*(it));
//			word.clear();
//			continue;
//		}
////		ans.append(1,*(it));
//	}
