
#include "addition.hpp"
#include <iostream>

int main(void)
{
	std::cout << "1 + 2 + 5 = " << sum<1, 2, 5>::value << std::endl;
}
