#include <iostream>
#include <inttypes.h>
#include <vector>
#include <iterator>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <map>


namespace KStep
{


bool isPrimeAks(int_fast64_t number)
{
	if(number == 2) return true;
	if (number == 3) return true;
	if (!(number % 2)) return false;
	if(!(number % 3)) return false;

	int_fast64_t i = 5;
	int_fast64_t w = 2;

	while(i * i <= number)
	{
		if(!(number % i)) return false;
		i += w;
		w = 6 - w;
	}

	return true;
}
std::vector<int_fast64_t> primesSmallerThan(const int_fast64_t& number)
{
	std::vector<int_fast64_t> result;
	for (int_fast64_t i = 2; i <= number ; i++)
	{
		if(isPrimeAks(i)) result.emplace_back(i);

	}
	return result;

}
int_fast64_t primePower(int_fast64_t prime_number, int_fast64_t number_to_factor_from)
{
//	auto start_read = std::chrono::steady_clock::now();
	int_fast64_t ans = 0;
	if(number_to_factor_from == 1) return 1;

	for(int_fast64_t i = 1; pow(prime_number,i) <= number_to_factor_from;i++)
	{
			if(!( number_to_factor_from % (int_fast64_t)pow(prime_number,i)) )
			{
				ans++;
			}
	}
	return ans;

}
bool isPrime(int_fast64_t number)
{

	if (number == 2) return true;
	if(! (number % 2)) return false;

	else
	{
		int_fast64_t number2 = number / 2;

		for( int_fast64_t i = 3 ; i <=number2 ;i++)
		{
			if (!(number % i )) return false;
		}
	}

		return true;

}
std::pair<std::vector<int_fast64_t>,int_fast64_t> prime_factors(int_fast64_t number)
{
	int_fast64_t number2= number / 2;
	std::map<int_fast64_t,int_fast64_t> prime_number_and_occurance;
	std::vector< int_fast64_t> ans;

	for(int_fast64_t i = 2; i <= number2;i++)
	{
		if(!(number % i) && isPrimeAks(i))
		{
			prime_number_and_occurance[i]=primePower(i,number);
		}

	}

	int_fast64_t k_of_number = 0;
for(auto& p : prime_number_and_occurance)
{
	ans.push_back(p.first);
	k_of_number+=p.second;
}

		return std::make_pair(ans,k_of_number);


}
std::pair<std::vector<int_fast64_t>,int_fast64_t> myprimeFactors(const int_fast64_t& number)
{
	std::vector<int_fast64_t> result;
	int_fast64_t counter = 0;
	if (number == 1)
	{
		result.push_back(0);
		return std::make_pair(result,counter);
	}

	if (number == 2)
	{
		result.push_back(number);
		return std::make_pair(result,++counter);
	}

	for (int_fast64_t factor = number-1; factor > 0;factor--)
	{
		if(!(number % factor) && number % (factor * factor)   )
		{
//			std::cout << number <<" is divisble by " << factor << std::endl;
			auto qq = myprimeFactors(factor);
//			std::cout <<"number of prime factors of "<< factor  << " is : " << qq.second << std::endl;
			if (qq.second ==1) // if factor is a prime.
			{
				counter++;
				result.push_back(factor);
			}
		}
		if (!(number % (factor * factor)) && factor!=1 )
		{
			int counter2 = 0; // count how many times factor*factor*factor ... is divisible with number.
			// i.e. 4 should be 2, 9 should be 2, 27 should be 3³ etc.
			for( int i = 2; pow(factor,i) <= number ;i++)
			{
				if(!(number % ((int)pow(factor,i))))
				{
					counter2++;
				}
			}
			auto qqq = myprimeFactors(factor);
			if (qqq.second == 1)
			{
				counter++;
				counter += counter2;
				result.push_back(factor);
			}
		}
	}
	if(!counter) counter++; // if counter == 0 it means this number is a prime.
	std::pair<std::vector<int_fast64_t>,int_fast64_t> r = std::make_pair(result,counter);
	return r;
}

int_fast64_t findkOfNumber(const int_fast64_t& number,const std::vector<int_fast64_t>& primeSmaller)
{
	int_fast64_t factor_counter = 0;
	for (const int_fast64_t& smaller_prime :  primeSmaller )
	{
		for (int power = 1; (int)pow(smaller_prime,power) <= number ;power++)
		{
			if (number % (int)pow(smaller_prime,power)) break;
			else factor_counter++;
		}

	}
	if (!factor_counter) return 1;
	return factor_counter;
}
//define factors(n)
//
//    z = 2
//
//    while (z * z <= n)
//
//        if (n % z == 0)
//            output z
//            n /= z
//
//        else
//            z++
//
//    if n > 1
//        output n
int_fast64_t findkOfNumber_fast( int_fast64_t number,const std::vector<int_fast64_t>& primeSmaller)
{
	int_fast64_t counter = 0;
	int_fast64_t a = number;
	for (const int_fast64_t& smaller_prime :  primeSmaller )
		{
		while( smaller_prime <= a)
		{
			if( !(number % smaller_prime))
				{
					number /= smaller_prime ;
//					std::cout<< "number after /= :" <<number<<std::endl;
					counter++;
				}
			else break;
		}
		if (number == 1) return counter;
		}
	return counter;
}
std::vector<std::pair <int_fast64_t, int_fast64_t>> kprimesStep(int k, int step, const int_fast64_t& m, const int_fast64_t& n)
    {
	std::vector<std::pair <int_fast64_t, int_fast64_t>>  result;
	std::vector<int_fast64_t> kprime_result;

	auto start_read = std::chrono::steady_clock::now();
	std::vector<int_fast64_t> primes_smaller = primesSmallerThan(n/2);
		auto end_read = std::chrono::steady_clock::now();
		auto diff_read = end_read - start_read;
		std::cout <<"duration of primesSmallerThan(n/2) "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;

		start_read = std::chrono::steady_clock::now();
		for( int_fast64_t number = m ; number <= n ; number++)
				{
					if(findkOfNumber_fast(number,primes_smaller) == k) kprime_result.emplace_back(number);
				}
		end_read = std::chrono::steady_clock::now();
		diff_read = end_read - start_read;
		std::cout <<"duration of findkOfPrime loop "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;


		for (auto it = kprime_result.begin();it != kprime_result.end();it++)
				{
					if ( std::binary_search(it,kprime_result.end(),*(it) + step)) result.emplace_back(std::make_pair(*(it),*(it) + step));

				}
		std::cout <<"\n"<<std::endl;
		for(auto&r : result)
			{
				std::cout << "[ " <<r.first <<" , " << r.second << " ] " <<std::endl;
			}
		return result;
    }
}



void test_prime_power()
{
if(KStep::primePower(2,16) ==4 ) std::cout << "test_prime_power test 1, success" <<std::endl;
else std::cout << "test 1 fail, KStep::primePower(2,16) came out as :"<<KStep::primePower(2,16) <<std::endl;

if(KStep::primePower(5,50) ==2 ) std::cout << "test_prime_power test 2, success" <<std::endl;
else std::cout << "test 2 fail, KStep::primePower(5,50) came out as :"<<KStep::primePower(5,50) <<std::endl;
if(KStep::primePower(7,686) == 3) std::cout << "test_prime_power test 3, success" <<std::endl;
else std::cout << "test 3 fail" <<std::endl;
if(KStep::primePower(11,14641) ==4 ) std::cout << "test_prime_power test 4, success" <<std::endl;
else std::cout << "test 4 fail" <<std::endl;
if(KStep::primePower(1,1) ==1 ) std::cout << "test_prime_power test 5, success" <<std::endl;
else std::cout << "test 5 fail" <<std::endl;
if(KStep::primePower(2,2) ==1 ) std::cout << "test_prime_power test 6, success" <<std::endl;
else std::cout << "test 6 fail" <<std::endl;
}

void test_is_prime()
{
	if(KStep::isPrimeAks(159890608811) == true ) std::cout << "test_is_prime test 1, success" <<std::endl;
	else std::cout << "test 1 fail, KStep::isPrime(159890608811) came out as false "<<std::endl;

	if(KStep::isPrimeAks(60312491917) == true ) std::cout << "test_is_prime test 2, success" <<std::endl;
	else std::cout << "test 2 fail, KStep::isPrime(60312491917) came out as false "<<std::endl;


}


void test_primesSmallerThan()
{
	auto ans = KStep::primesSmallerThan(100);

	for (auto number : ans)
	{
		std::cout << number << std::endl;
	}
}
void test_findkOfNumber_fast()
{
	auto ans = KStep::primesSmallerThan(2113722);
	auto cor = KStep::findkOfNumber_fast(2113722 ,ans);
	if(cor== KStep::findkOfNumber(2113722,ans)) std::cout << "test_findkOfNumber_fast 1, success" <<std::endl;
	else std::cout << "test_findkOfNumber_fast 1 fail, KStep::findkOfNumber_fast(24,ans)  came out as "<<cor<< std::endl;
}

int main()
{
	test_findkOfNumber_fast();
	test_prime_power();
	test_is_prime();
	std::cout<< KStep::isPrimeAks(3011)<<std::endl;
	auto start_read = std::chrono::steady_clock::now();
	KStep::kprimesStep(10, 8, 242536, 242570);
	auto end_read = std::chrono::steady_clock::now();
	auto diff_read = end_read - start_read;
	std::cout <<"duration of kprimesStep(10, 8, 242536, 242570) "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;



	start_read = std::chrono::steady_clock::now();
	KStep::kprimesStep(6, 8, 2627371, 2627581);
	end_read = std::chrono::steady_clock::now();
	diff_read = end_read - start_read;
	std::cout <<"duration of kprimesstep(6,8,2627371,2627581) "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;


	start_read = std::chrono::steady_clock::now();
	KStep::kprimesStep(6, 8, 2627408, 2627504);
	end_read = std::chrono::steady_clock::now();
	diff_read = end_read - start_read;
	std::cout <<"duration of kprimesstep(6,8,2627408,2627504) "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;


	start_read = std::chrono::steady_clock::now();
	KStep::kprimesStep(2, 10, 0, 50);
	end_read = std::chrono::steady_clock::now();
	diff_read = end_read - start_read;
	std::cout <<"duration of kprimesstep(2,10,0,50) "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;

	start_read = std::chrono::steady_clock::now();
	KStep::kprimesStep(2, 2, 0, 50);
	end_read = std::chrono::steady_clock::now();
	diff_read = end_read - start_read;
	std::cout <<"duration of kprimesstep(2,2,0,50) "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;

	start_read = std::chrono::steady_clock::now();
	KStep::kprimesStep(6, 14, 2113665, 2113889);
	end_read = std::chrono::steady_clock::now();
	diff_read = end_read - start_read;
	std::cout <<"duration of kprimes_step(6, 14, 2113665, 2113889) "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;





	return 0;
}
