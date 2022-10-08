
#include "addition.hpp"
#include "metatoi.hpp"
#include <iostream>

int main(void)
{
	std::cout << "---------------SUM---------------\n";
	std::cout << "1 + 2 + 5 = " << int_sum<1, 2, 5>::value << std::endl;
	std::cout << "5 + 5 + 5 = " << sum<5, 5, 5> << std::endl;
	std::cout << "(uint32_t)-1 + -50 + '2' = " << sum<(uint32_t)-1, -50, '2'> << std::endl;
	std::cout << "(uint64_t)-1 + -50 + '2' = " << sum<(uint64_t)-1, -50, '2'> << std::endl;
	
	
	std::cout << "\n\n---------------ATOI--------------\n";
	std::cout << "56: " << metatoi<'5', '6'>::value << std::endl;
	std::cout << "222: " << metatoi<'2', '2', '2'>::value << std::endl;
	std::cout << "45677886: " << metatoi<'4', '5', '6', '7', '7', '8', '8', '6'>::value << std::endl;
	// std::cout << "-10: " << metatoi<'-', '1', '0'>::value << std::endl;

}
