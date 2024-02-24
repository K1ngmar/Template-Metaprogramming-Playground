
#include "tuple.h"
#include <iostream>

int main()
{
	km::Tuple a(1, (char*)"twee", '3', 4.5f);
	km::Tuple<size_t, char*, std::string, float> b(1, (char*)"twee", "drie", 4.5f);

	std::cout << km::Get<0>(a) << ", " << km::Get<1>(a) << ", " << km::Get<2>(a) << ", " << km::Get<3>(a) << std::endl;
	std::cout << b.Get<0>() << ", " << b.Get<1>() << ", " << b.Get<2>() << ", " << b.Get<3>() << std::endl;


	// const auto& [first, second, third, fourth] = a;

	return 0;
}
