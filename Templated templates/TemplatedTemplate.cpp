
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
 * @tparam Container (This is a template template parameter because the conatiner itself is templated, we use a parameter pack because not all std::containers take the same amount of arguments.)
*/
template <class T, template<class ...> class Container>
void SplitContainerAndValue(const Container<T>& contianer)
{
	std::cout << "A `" << typeid(Container<T>).name() << "` with type `" << typeid(T).name() << "`\n";
}

// To support maps internal types you probably want to specialize it like this
template <class Key, class Value, template<class ...> class Container>
void SplitContainerAndValue(const Container<Key, Value>& contianer)
{
	std::cout << "A `" << typeid(Container<Key, Value>).name() << "` with key type: `" << typeid(Key).name() << "` and value type: `" << typeid(Value).name() << "`\n";
}

// base
template<class ...>
struct GetFirstTypeOfParameterPack
{
};

// single value (gets called if only one value in pack)
template<class T>
struct GetFirstTypeOfParameterPack<T>
{
	using type = T;
};

// Extract first value from pack.
template<class T, class ...Ts>
struct GetFirstTypeOfParameterPack<T, Ts...>
{
	using type = T;
};


// But it would be cool if we had only one function to do this.
// Here we have an additional parameter pack that catches all the template arguments of the container.
template <class T, template<class ...> class Container, class ...AdditionalContainerParams>
void SplitContainerAndValueAllroundVersion(const Container<T, AdditionalContainerParams...>& contianer)
{
	if constexpr (std::is_same_v<Container<T, AdditionalContainerParams...>, std::map<T, AdditionalContainerParams...> >)
	{
		std::cout << "A `" << typeid(Container<T, AdditionalContainerParams...>).name();
		std::cout << "` with key type: `" << typeid(T).name();
		std::cout <<  "` and value type: `" << typeid(typename GetFirstTypeOfParameterPack<AdditionalContainerParams...>::type).name() << "`\n";
	}
	else
	{
		std::cout << "A `" << typeid(Container<T, AdditionalContainerParams...>).name() << "` with type `" << typeid(T).name() << "`\n";
	}

	// Or you just use the value type like this (works for both map and vector):
	using ValueType = typename Container<T, AdditionalContainerParams...>::value_type;
	std::cout << "value type is: `" << typeid(ValueType).name() << "`\n";
}

int main()
{
	SplitContainerAndValue(std::deque<int>{1, 2, 3});
	SplitContainerAndValue(std::vector<double>{1, 2, 3});
	SplitContainerAndValue(std::map<int, float>{{1, 2}});

	SplitContainerAndValue(std::deque<size_t>{1, 2, 3});
	SplitContainerAndValue(std::deque<float>{1, 2, 3});
	SplitContainerAndValue(std::deque<std::string>{"abc", "def"});

	std::cout << "\nAllround version:\n\n";

	SplitContainerAndValueAllroundVersion(std::vector<int>{1, 2});
	SplitContainerAndValueAllroundVersion(std::vector<float>{1, 2});
	SplitContainerAndValueAllroundVersion(std::map<int, float>{{1, 2}});
	SplitContainerAndValueAllroundVersion(std::map<float, int>{{1, 2}});
	SplitContainerAndValueAllroundVersion(std::map<std::string, std::string>{{"one", "two"}});

}
