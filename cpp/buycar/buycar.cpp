#include <iostream>
#include <algorithm>

#include <vector>

namespace BuyCar
{

  static std::vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth)
  {


	  double old_car = static_cast<double>(startPriceOld);
//	  std::cout << old_car << std::endl;

	  double new_car = static_cast<double>(startPriceNew);
//	  std::cout << new_car << std::endl;

	  double savings = static_cast<double>(savingperMonth);
//	  std::cout << savings << std::endl;



	  if (startPriceOld >= startPriceNew)
		  {
		  	  return {0,startPriceOld-startPriceNew };
		  }
	  double my_money = 0;

	  int month = 0;
	  while ( (my_money+old_car)  <= new_car && month < 10000 )
	  {
		  my_money += savings;
		  std::cout << "my money: " << my_money << std::endl;
		  old_car *= (100.0 - percentLossByMonth) / 100;
		  std::cout << "old car: " << old_car << std::endl;

		  new_car *= (100.0 - percentLossByMonth) / 100;
		  std::cout << "new_car : " << new_car << std::endl;


		  if(!(month % 2)) percentLossByMonth += 0.5;
		  month++;
	  }

	  std::cout << my_money + old_car - new_car << std::endl;
	  return {month,int(std::round(my_money + old_car - new_car)) };
  }
};



int main()
{
	auto a = BuyCar::nbMonths(12000,8000,1000,1.5);
	for( auto&b : a)
	{
		std::cout << b <<std::endl;
	}


	std::cout <<static_cast<int> (5.51) << std::endl;


	return 0;
}
