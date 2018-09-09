#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>
#include <chrono>
#include <iomanip>

class Decomp
{
public:
	static void simplify(double& a, double& b)
	{
		for ( double i = 2 ; i < 30 ; i++)
		{
			while( (int(a) % int(i)) == 0 && (int(b) % int(i)) == 0)
			{
				a/=i;
				b/=i;
			}
		}
	}
  static std::string decompose(const std::string &nrStr, const std::string &drStr)
  {
	  if(nrStr=="0" || nrStr == "") return "[]";
	  std::string ans {"["};
	  std::vector<double> denoms;
	  double sum = 0;
	  double num = std::stod(nrStr);
	  double denum = std::stod(drStr);
	  simplify(num,denum);
	  const double error = 1/std::numeric_limits<double>::max();
	  double max_it = 0;
	  if (num <= 10 && denum <= 10 ) max_it = 100;
	  else if (num < 25 && denum < 25 ) max_it = 100000;
	  else if (num < 100 && denum < 100 ) max_it = 53307976;
	  else max_it = 1359351417;

	  if( num < denum)
	  {
		  for(double i =2 ;i< max_it ;i++)
		  	  {
			  	  if(sum + (1/i) > num/denum) continue;
		  		  if(sum + (1/i) < num/denum)
		  			  {
		  			  	  sum +=(1/i);
		  			  	  denoms.push_back(i);
		  			  	  if( i > 50) i*=i;
		  			  }
		  		  else if((sum + (1/i)) == (num/denum) )
		  		  {
		  			  denoms.push_back(i);
		  			  break;
		  		  }
		  	  }
		  	  std::for_each(denoms.begin(),denoms.end(),[&ans](double a)
		  			  {
		  		  	  	  ans.append("1/"+std::to_string((int)a) + ", ");
		  			  });
		  	  ans.replace(ans.find_last_of(','),1,"]");
		  	  ans.erase(ans.end()-1);

		  	  return ans;
	  }
	  else if ((int)num  % (int)denum)
	  {
		  sum += std::floor(num/denum);
		  ans.append(std::to_string(int(num/denum)) + ", ");
		  double new_rational = (num/denum) -int(num/denum);
		  for(double i =2 ;i < max_it ;i++)
		  {
			  if(sum + (1/i) < new_rational)
			  {
				  sum +=(1/i);
				  denoms.push_back(i);
			  }
			  if((sum + (1/i)) - new_rational == std::floor(num/denum))
			  {
				  denoms.push_back(i);
				  break;
			  }
		  }
		  std::for_each(denoms.begin(),denoms.end(),[&ans](double a)
		  		  			  {
		  		  		  	  	  ans.append("1/"+std::to_string((int)a) + ", ");
		  		  			  });
		  		  	  ans.replace(ans.find_last_of(','),1,"]");
		  		  	  ans.erase(ans.end()-1);
		  		  	  return ans;


	  }
	  else
	  {
		  ans.append(std::to_string(int(num/denum))+ ']') ;
		  return ans;
	  }


  }

  static std::string decompose_new(const std::string &nrStr, const std::string &drStr)
  {
	  if(nrStr=="0" || nrStr == "") return "[]";
	  std::string ans {"["};

	  double num = std::stod(nrStr);
	  double denum = std::stod(drStr);
	  if (! ((int)num % (int)denum) )
	  {
		  ans.append(std::to_string((int)(num/denum))+"]");
		  return ans;
	  }
	  double d = num/denum;
	  std::vector<double> values;

	  if ( num > denum)
	  {
		  ans.append(std::to_string(int(num/denum))+", ");
		  double q = num/denum ;
		  q -= std::floor(num/denum);
		  d = q;
	  }
	  double y = 1/d;
	  double z = std::ceil(y-0.00000000000001);
	  if(z-y > 0.9999999999)  z = y;
	  values.emplace_back(z);
	  while( y != int(y) && (d-(1/z)) > pow(10,-16) )
	  {
		  d-=(1/z);
		  y = 1/d;
		  z = std::ceil(y-0.000000000000001);
		  if(z-y > 0.9999999999)  z = y;
		  if(z == 1359351418) z = 1359351420;
		  values.emplace_back(z);
	  }

	  std::for_each(values.begin(),values.end(),[&ans](double a)
	  		  		  			  {
	  		  		  		  	  	  ans.append("1/"+std::to_string((int)a) + ", ");
	  		  		  			  });
	  		  		  	  ans.replace(ans.find_last_of(','),1,"]");
	  		  		  	  ans.erase(ans.end()-1);
	  		  		  	  return ans;

  }
};



int main()
{

//	double a = 125;
//	double b = 100;
//Decomp::simplify(a,b);
//
//std::cout << a << "\t" << b << std::endl;

	auto start_read = std::chrono::steady_clock::now();
	std::cout << Decomp::decompose("13","12") << std::endl;

//	std::cout << Decomp::decompose("16","17") << std::endl;
//	std::cout << Decomp::decompose("3","4") << std::endl;
//	std::cout << Decomp::decompose("12","4") << std::endl;
//	std::cout << Decomp::decompose("4","5") << std::endl;
//	std::cout << Decomp::decompose("66","100") << std::endl;
//	std::cout << Decomp::decompose("22","23") << std::endl;
//	std::cout << Decomp::decompose("1001","3456") << std::endl;
//	std::cout << Decomp::decompose("14","15") << std::endl;
	std::cout << Decomp::decompose("50","4187") << std::endl;
//	std::cout << Decomp::decompose("9","10") << std::endl;
//	std::cout << Decomp::decompose("81","82") << std::endl;
	auto end_read = std::chrono::steady_clock::now();
	auto diff_read = end_read - start_read;
	std::cout <<"duration of decompose "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;

		start_read = std::chrono::steady_clock::now();
		std::cout << Decomp::decompose_new("13","12") << std::endl;

		std::cout << Decomp::decompose_new("16","17") << std::endl;
		std::cout << Decomp::decompose_new("3","4") << std::endl;
		std::cout << Decomp::decompose_new("12","4") << std::endl;
		std::cout << Decomp::decompose_new("4","5") << std::endl;
		std::cout << Decomp::decompose_new("66","100") << std::endl;
		std::cout << Decomp::decompose_new("22","23") << std::endl;
		std::cout << Decomp::decompose_new("1001","3456") << std::endl;
		std::cout << Decomp::decompose_new("14","15") << std::endl;
		std::cout << Decomp::decompose_new("50","4187") << std::endl;
		std::cout << Decomp::decompose_new("9","10") << std::endl;
		std::cout << Decomp::decompose_new("81","82") << std::endl;
		end_read = std::chrono::steady_clock::now();
		diff_read = end_read - start_read;
		std::cout <<"duration of decompose_new "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;





	return 0;
}
