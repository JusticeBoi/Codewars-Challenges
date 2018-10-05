#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <chrono>
class PrimeDecomp
{
public:
    static std::string factors(long long lst);
};

bool isPrimeAks(long long number)
{
	if (!(number % 2)) return false;
	if(!(number % 3)) return false;
	if(number == 2) return true;
	if (number == 3) return true;

	long long i = 5;
	long long w = 2;

	while(i * i <= number)
	{
		if(!(number % i)) return false;
		i += w;
		w = 6 - w;
	}

	return true;
}
long long primePower(long long prime_number, long long number_to_factor_from)
{
//	auto start_read = std::chrono::steady_clock::now();
	long long ans = 0;
	if(number_to_factor_from == 1) return 1;

	for(long long i = 1; pow(prime_number,i) <= number_to_factor_from;i++)
	{
			if(!( number_to_factor_from % (long long)pow(prime_number,i)) )
			{
				ans++;
			}
	}
	return ans;
}

std::map<long long,long long> prime_factors(long long number)
{
	if(isPrimeAks(number)) return {{number,1}} ;
	long long number2= number / 2;
	std::map<long long,long long> prime_number_and_occurance;
	std::vector< long long> ans;
	long long occurance = 0;

	for(long long i = 2; i <= number2;i++)
	{
		if(!(number % i) && isPrimeAks(i))
		{

			occurance=primePower(i,number);
			prime_number_and_occurance[i] = occurance;
			number/=(pow(i,occurance));
			if(number == 1) break;
		}
	}
	return prime_number_and_occurance;
}
std::string writePretty(const std::map<long long, long long>& p_and_occu)
{
	std::string pretty_answer = std::string();
	for(const auto& pair : p_and_occu)
	{
		if(pair.second == 1)
		{
			pretty_answer+="(" + std::to_string(pair.first) + ")";
		}
		else
		{
			 pretty_answer += "(" + std::to_string(pair.first) + "**" + std::to_string(pair.second) + ")";
		}
	}
	return pretty_answer;
}
std::string PrimeDecomp::factors(long long lst)
{
	auto p_and_occu_map = prime_factors(lst);

	std::string answer =  writePretty(p_and_occu_map);

	return answer;
}

long long factorial_recursive(long long a)
{
	if(a == 0) return 1;
	else if (a == 1) return 1;

	return a *factorial_recursive(a-1);
}

long long factorial_loop (long long a)
{
	long long ans= 1;
	if ( a == 0 ) return 1;
	else if (a == 1) return 1;
	else
	{
		for(long long i = 2; i<= a ;++i)
		{
			ans *= i ;
		}
		return ans;
	}

}

int main()
{
//	auto ans = prime_factors(2);
//	for (auto& a : ans)
//	{
//		std::cout << "prime : "<<a.first << " occurance : " <<a.second <<std::endl;
//	}
//	std::cout << PrimeDecomp::factors(782611830)<<std::endl;
	auto start_read = std::chrono::steady_clock::now();
	std::cout << factorial_recursive(25) <<std::endl;
	auto end_read = std::chrono::steady_clock::now();
	auto diff_read = end_read - start_read;
	std::cout <<"factorial_recursive : "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;

	start_read = std::chrono::steady_clock::now();
	std::cout << factorial_loop(25) <<std::endl;
	end_read = std::chrono::steady_clock::now();
	diff_read = end_read - start_read;
	std::cout <<"factorial_loop : "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;




	return 0;
}
