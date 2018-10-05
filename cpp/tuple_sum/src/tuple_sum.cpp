#include <iostream>
#include <tuple>
#include <vector>


//template<class... Types>
//struct count {
//    static const std::size_t value = sizeof...(Types);
//};
template <typename... Ts>
double tuple_sum(const std::tuple<Ts...>& tpl)
{
	static const std::size_t value = sizeof...(Ts);
	std::cout <<value<<std::endl;

//	auto b = std::tuple_size<Ts...>::value;
//	std::cout << b << std::endl;
}

using namespace std::string_literals;
int main()
{

	tuple_sum(std::make_tuple(3.14, 42, 'a', "Hello", "World"s,
            std::vector<int>{1, 2, 3}));

}
