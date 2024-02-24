
#include "tuple.h"
#include <iostream>

int main()
{
	km::Tuple a(1, (char*)"twee", '3', 4.5f);
	km::Tuple<size_t, char*, std::string, float> b(1, (char*)"twee", "drie", 4.5f);

	std::cout << b.Get<1>() << std::endl;
	// const auto& [first, second, third, fourth] = a;

	return 0;
}
