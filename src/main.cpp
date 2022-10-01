
#include "addition.hpp"
#include <iostream>

int main(void)
{
	std::cout << "1 + 2 + 5 = " << int_sum<1, 2, 5>::value << std::endl;

	std::cout << "5 + 5 + 5 = " << sum<5, 5, 5> << std::endl;

	std::cout << "(uint32_t)-1, -50, '2' = " << sum<(uint32_t)-1, -50, '2'> << std::endl;

	std::cout << "(uint64_t)-1, -50, '2' = " << sum<(uint64_t)-1, -50, '2'> << std::endl;
}
