#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <inttypes.h>
#include <assert.h>

std::string highestScoringWord(const std::string &str);


int main()
{
std::string chars ="abcdefghijklmnopqrstuvwxyz";

std::string words {"aaa bbb    ccc   "};

const char m_char = 'b';

std::cout << int(m_char) << std::endl;

//std::cout <<highestScoringWord(words) << std::endl;

    return 0;
}



std::string highestScoringWord(const std::string &str)
{
std::string chars ="abcdefghijklmnopqrstuvwxyz";

std::istringstream iss(str);
std::string m_words;

uint_fast32_t sum = 0;
uint_fast32_t max_sum = 0;
std::string answer;
while(iss >>m_words)
{
	for(std::string::size_type i = 0 ; i < m_words.size();++i)
	{
	assert(isalpha(m_words[i]) && "words can only contain letters");
	auto loc = chars.find(m_words[i]);
	if(loc < 0 || loc > 25)
		{
			std::cerr <<"somethings wrong" << std::endl;
			return "error";
		}
	sum += (uint_fast32_t)loc + 1;
	}
	if(sum > max_sum)
	{
		max_sum = sum ;
		answer = m_words;

	}
	sum = 0;
}
  return answer;
}
