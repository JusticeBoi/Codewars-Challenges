//FIND BETTER ANSWER FOR REFERENCE IN BOTTOM


#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
static std::unordered_map<long long,char> look_up_table ={
		{0,'0'},
		{1,'1'},
		{2,'2'},
		{3,'3'},
		{4,'4'},
		{5,'5'},
		{6,'6'},
		{7,'7'},
		{8,'8'},
		{9,'9'},
		{10,'A'},{11,'B'},{12,'C'},{13,'D'},{14,'E'},{15,'F'},{16,'G'},{17,'H'},{18,'I'},{19,'J'},
		{20,'K'},{21,'L'},{22,'O'},{23,'M'},{24,'N'},{25,'O'},{26,'P'},{27,'Q'},{28,'R'},{29,'S'},
		{30,'T'},{31,'U'},{32,'V'},{33,'W'},{34,'X'},{35,'Y'},{36,'Z'}
};

class Dec2Fact
{
public:
  static std::string dec2FactString(long long nb);
  static long long factString2Dec(const std::string &str);
};
long long factorial ( const long long number);
std::string Dec2Fact::dec2FactString(long long nb)
{
	std::cout <<"long long : "<< nb <<std::endl;
	std::string ans = std::string();
	long long max_fact = 0;
	while(nb >= factorial(max_fact) )
	{
		max_fact++;
	}
	max_fact-=1;
	long long nb_copy = nb;
	for(long long num = max_fact ; num > 0 ; --num)
	{
//		std::cout <<"factorial(num): " << factorial(num) <<std::endl;
//		std::cout << nb_copy / factorial(num) << std::endl;
		ans+=(look_up_table [nb_copy / factorial(num)]);
		nb_copy= nb_copy -  (nb_copy/factorial(num)) * factorial(num);
	}
	ans.append("0");
	return ans;
}

long long Dec2Fact::factString2Dec(const std::string &str)
{
	std::cout <<"str : "<< str <<std::endl;
	long long key ;
	long long  ans = 0;
	char the_char;
	auto findKeyFromValue = [&the_char,&key](const std::pair<long long,char>& a_pair )
				{
		if (a_pair.second == the_char) key =a_pair.first;
				};
	int i = 0;
	for(auto c = str.rbegin() ; c != str.rend();++c,++i)
	{
		the_char = *c;
		std::for_each(look_up_table.begin(),look_up_table.end(),findKeyFromValue);
		ans += (key * factorial(i));
	}
	return ans;
}

//		for (auto& ch : str)
//		{
//				the_char = ch;
//				std::for_each(look_up_table.begin(),look_up_table.end(),findKeyFromValue);
//				ans.append(std::to_string(key));
//		}
//		long long ret = std::stoll(ans);
int main()
{
//std::cout << factorial(10) -1 <<std::endl;
//
//std::cout << factorial(6) << std::endl;
//	for(auto& u : look_up_table)
//	{
//		std::cout << u.first <<std::endl;
//	}
	std::cout <<Dec2Fact::dec2FactString(2982) <<std::endl;
	std::cout <<Dec2Fact::factString2Dec("01") <<std::endl;
	return 0;
}

long long factorial (const long long number)
{
	if(!number) return 1;
	long long ans = 1;
	for (long i = 1; i<=number ;i++)
	{
		ans*=i;
	}
	return ans;
}

//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <cassert>
//
//class Dec2Fact {
//public:
//  static std::string dec2FactString(long long nb);
//  static long long factString2Dec(const std::string &str);
//};
//
//char toBase36(int value) {
//  assert((value >= 0) && (value < 36));
//  static char encoding[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//  return encoding[value];
//}
//
//int toBase10(char value) {
//  assert(value >= '0');
//  if (value <= '9')
//    return (value - '0');
//
//  assert((value >= 'A') && (value <= 'Z'));
//  return value - 'A';
//}
//
//std::string Dec2Fact::dec2FactString(long long nb) {
//  using namespace std;
//
//  string result;
//  result.reserve(14);
//
//  int factor = 1;
//
//  // this assembles the result in reverse
//  do {
//    result += toBase36(nb % factor);
//    nb /= factor;
//    ++factor;
//  } while (nb != 0);
//
//  // reverse to correct the buildup
//  reverse(begin(result), end(result));
//
//  return result;
//}
//
//long long Dec2Fact::factString2Dec(const std::string& str) {
//  using namespace std;
//
//  long long result = 0;
//
//  string reversed(str);
//  reverse(begin(reversed), end(reversed));
//
//  long long factor = 1;
//  int i = 1;
//
//  for (auto c : reversed) {
//    result += factor * toBase10(c);
//    factor *= i;
//    ++i;
//  }
//
//  return result;
//}
