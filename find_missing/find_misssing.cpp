#include <iostream>
#include <vector>

static long findMissing(std::vector<long>);
int main()
{
    std::vector<long> asd {-1, -3, -7};


std::cout<< findMissing(asd) << std::endl;

std::cout << asd.front() << std::endl;

return 0;
}

static long findMissing(std::vector<long> list){

if (list.size() < 3)
{
    std::cerr << "at least three arguments must be provided" << std::endl;
}
long last_element = list[list.size()-1];
long first_element = list[0];
long increase = (last_element-first_element)/(long)list.size();


for( auto it = list.begin()+1;it!=list.end();it++)
{
    if( (*it) != *(it-1) + increase )
    {
        return *(it-1) + increase;
    }
}

return 0;
}



// static long findMissing(std::vector<long> list){

// if (list.size() < 3)
// {
//     std::cerr << "at least three arguments must be provided" << std::endl;
// }

// double increase = double((list[list.size()-1]- list[0]))/(double)list.size() ;


// for( auto it = list.begin()+1;it!=list.end();it++)
// {
//     if( (*it) != *(it-1) + increase )
//     {
//         return *(it-1) + increase;
//     }
// }

// std::cout << "not a valid sequence" << std::endl;
// return 0;
// }