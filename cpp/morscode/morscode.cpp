#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <memory>

//class Chars
//{
//private:
//	std::unique_ptr<Chars> dash_ptr;
//	std::unique_ptr<Chars> dot_ptr;
//	std::string m_char;
//public:
//	Chars(std::string a_char):m_char(a_char){};
//
//
//};
//
//class MorseTree
//{
//	friend class Chars;
//private:
//	std::unique_ptr<Chars> head;
//	//std::unique_ptr<Chars> tail;
//public:
//	MorseTree()
//{
//	head->dash_ptr = Chars("E");
//	head->dot_ptr = Chars("T");
//	init();
//}
//	void init()
//	{
//
//	}
//
//
//
//};


std::map<std::string,std::string> MORSE_CODE = {
		{".","E"}, {"-","T"},{"EE","I"},{"EEE","S"},{"EEEE","H"},{"EEET","V"},{"EET","U"},{"ET","A"},{"ETE","R"},
		{"ETEE","L"},{"ETT","W"},{"ETTT","J"},{"ETTE","P"},{"TE","N"},{"TEE","D"},{"TEEE","B"},{"TEET","X"},{"TETE","C"},
		{"TETT","Y"},{"TET","K"},{"TT","M"},{"TTT","O"},{"TTE","G"},{"TTEE","Z"},{"TTET","Q"},{"EETE","F"},
		{"sss"," "},{"ETETET","."},{"TETETT","!"},{"EEETTTEEE","SOS"}
};
std::string decodeMorse(std::string morseCode);
void ReplaceStringInPlace(std::string& subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}
int main()
{



std::string qq {".... . -.--   .--- ..- -.. ."};
std::string word {"   .   . "};

std::cout <<decodeMorse(word) << std::endl;

	return 0;
}



#





