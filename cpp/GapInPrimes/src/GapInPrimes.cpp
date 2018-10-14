#include <iostream>
#include <utility>


bool isPrimeAks(long long number)
{
	if(number == 2) return true;
	if (number == 3) return true;
	if (!(number % 2)) return false;
	if(!(number % 3)) return false;

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

int diffBetweenMeAndNextPrime(long long prime )
{
    for (long long next_p = prime + 1 ; ; ++next_p )
    {
        if(isPrimeAks(next_p) ) {
           
            return next_p - prime ;

        }
    }
}


class GapInPrimes
{
    public:
         static std::pair <long long, long long> gap(int g, long long m, long long n);
};

std::pair<long long, long long > GapInPrimes::gap(int g, long long m, long long n )
{

for( long long number = m ; number != n-1 ; ++number)
{
   if (isPrimeAks(number)){ 
       if (diffBetweenMeAndNextPrime(number) == g )
       {
             return std::make_pair(number,number + g ); 
       }

   }

}

return std::make_pair(0,0);

}

int main()
{
    auto ans = GapInPrimes::gap(10,300,400);
    std::cout<<"first number : "<<ans.first << " second number : " << ans.second << std::endl; 
    std::cout <<"diffbetween : " << diffBetweenMeAndNextPrime(101) ; 
    return 0;
}








