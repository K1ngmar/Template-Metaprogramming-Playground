
#include <iostream>
#include <string>

#include <map>
#include <deque>
#include <vector>
#include <set>
#include <list>

// https://www.ibm.com/docs/en/zos/2.2.0?topic=only-template-template-arguments-c

/*!
 * @brief Split the container type and value type.
 * @tparam T the value type of the container.
 * @param AdditionalContainerParams -
 * @tparam Container the container pack, (this is a parameter pack because not every container has the same amout of parameters, and the value type will always be the first parameter)
*/
template <class T, template<class...> class Container>
void SplitContainerAndValue(const Container<T>& contianer)
{
	if constexpr (std::is_integral_v<T>)
	{
		std::cout << "Element type is integral!\n";
	}
	else
	{
		std::cout << "Element type is not integral.\n";
	}
}

// for map you probably want to specialize it like this
template <class Key, class Value, template<class... AdditionalContainerParams> class Container>
void SplitContainerAndValue(const Container<Key, Value>& contianer)
{
	if constexpr (std::is_integral_v<Key>)
	{
		std::cout << "Key type is integral!\n";
	}
	else
	{
		std::cout << "key type is not integral.\n";
	}
}

// template <class T, template<class AdditionalContainerParams> class Container>
// void SplitContainerAndValueAllroundVersion(const Container<T, AdditionalContainerParams>& contianer)
// {
// 	if constexpr (std::is_integral_v<T>)
// 	{
// 		std::cout << "Element type is int!\n";
// 	}
// 	else
// 	{
// 		std::cout << "Element type is not int\n";
// 	}
// }

int main()
{
	SplitContainerAndValue(std::deque<int>{1, 2, 3});
	SplitContainerAndValue(std::vector<double>{1, 2, 3});
	SplitContainerAndValue(std::map<int, float>{{1, 2}});

	SplitContainerAndValue(std::deque<size_t>{1, 2, 3});
	SplitContainerAndValue(std::deque<float>{1, 2, 3});
	SplitContainerAndValue(std::deque<std::string>{"abc", "def"});

}
