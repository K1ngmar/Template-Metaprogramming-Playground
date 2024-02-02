
#include <iostream>
#include <string>

#include <map>
#include <deque>
#include <vector>
#include <set>
#include <list>

template <class T, template<class...> class Container>
void SplitContainerAndValue(const Container<T>& contianer)
{
	constexpr if (T == int)
	{
		std::cout << "Element type is int!\n"
	}
	else
	{
		std::cout << "Element type is not int\n";
	}
}

int main()
{
	SplitContainerAndValue(std::deque<int>{1, 2, 3});
	SplitContainerAndValue(std::vector<int>{1, 2, 3});
	SplitContainerAndValue(std::list<int>{1, 2, 3});

	SplitContainerAndValue(std::deque<size_t>{1, 2, 3});
	SplitContainerAndValue(std::deque<float>{1, 2, 3});
	SplitContainerAndValue(std::deque<std::string>{1, 2, 3});
}
