#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>


namespace Johnann
{

  static std::vector<long long> john(long long n);
  static std::vector<long long> ann(long long n);
  long long sumJohn(long long n);
 long long sumAnn(long long n);
    };



std::vector<long long> Johnann::john(long long n)
{
	std::vector<long long> ans = {0};
	for(int i = 1 ; i < n ;i++) //when i =1 we are doing 2 i.e.
	{
		long long from_anna = ann(ans.back() + 1).back();
		ans.emplace_back(i - from_anna  );

	}
	return ans;

}
std::vector<long long> Johnann::ann(long long n)
{
	std::vector<long long> ans = {1};
		for(int i = 1 ; i < n ;i++) //when i =1 we are doing 2 i.e.
		{
			long long from_john = john(ans.back() + 1).back();
			ans.emplace_back(i - from_john  );

		}
		return ans;
}

//  std::vector<long long> Johnann::john(long long n)
//		{
//    	 if (n == 1)
//    		 {
//    		 std::cout <<"n = 0 in john" << std::endl;
//    		 return {0};
//    		 }
//    	 else
//    	 {
//			 auto to_return= john(n-1);
//    		  long long t = to_return.back();
////    		  std::cout <<"t in john at n : " <<n <<" is :  "<<t<<std::endl;
//    		  long long annas = ann(t+1).back();
////    		  std::cout <<"annas in john at n : " <<n <<" is :  "<<annas<<std::endl;
////    		  std::cout <<" n - annas : " <<n - annas <<std::endl;
//    		  to_return.emplace_back(n - annas-1);
//    		 return to_return;
//    	 }
//		}
//  std::vector<long long> Johnann::ann(long long n)
//		{
// 	 if (n == 1)
// 		 {
//		 std::cout <<"n = 1 in ann" << std::endl;
//
//		 return {1};
// 		 }
// 	 else
// 	 {
//		 auto to_return= ann(n-1);
//
// 	 	 long long t = to_return.back();
// 	 	 long long q = john(t+1).back();
// 	 	 to_return.emplace_back(n - q -1);
// 	 	 return to_return;
//
// 	 }
//
//		}

  long long Johnann::sumJohn(long long n)
  {
	auto start_read = std::chrono::steady_clock::now();

	  std::vector<long long> result = Johnann::john(n);

	  auto ans = accumulate(result.begin(),result.end(),0);
	  std::cout << ans <<std::endl;
	  auto end_read = std::chrono::steady_clock::now();
	  			auto diff_read = end_read - start_read;
	  			std::cout <<"duration of Johnann::sumJohn "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;

	  return ans;
  }
  long long Johnann::sumAnn(long long n)
  {
	  auto start_read = std::chrono::steady_clock::now();
	  std::vector<long long> result = Johnann::ann(n);

	  auto ans = accumulate(result.begin(),result.end(),0);
	  std::cout << ans <<std::endl;
	  auto end_read = std::chrono::steady_clock::now();
	 	  			auto diff_read = end_read - start_read;
	 	  			std::cout <<"duration of Johnann::sumAnn "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;

	  return ans;
  }


int main()

{
//auto ans = Johnann::john(15);
//auto ans2 = Johnann::ann(50);
	auto start_read = std::chrono::steady_clock::now();
	std::cout <<"sum ann : " << Johnann::sumAnn(3000)<<std::endl;
	std::cout <<"sum ann : " << Johnann::sumAnn(150)<<std::endl;
	std::cout <<"sum ann : " << Johnann::sumAnn(112)<<std::endl;
	auto end_read = std::chrono::steady_clock::now();
	auto diff_read = end_read - start_read;
	std::cout <<"duration of sum anns "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;



//std::cout << "in main " <<std::endl;
//int counter = 1;
//
//for(auto b : ans)
//{
//	std::cout <<counter++<<"\t"<< b << std::endl;
//}
//
//std::cout <<"ann " << std::endl;
//counter = 1;
//for(auto b : ans2)
//{
//	std::cout <<counter++<<"\t"<< b << std::endl;
//}
	return 0;
}
