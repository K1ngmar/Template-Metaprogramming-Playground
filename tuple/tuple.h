
#pragma once

#include <stdlib.h>
#include <utility>

namespace km
{

	template <size_t i, class T>
	struct TupleItem
	{
		T item;

		TupleItem(const T&& val) : item(std::forward(val))
		{
		}
	};

	template <size_t i, class ...Ts>
	struct Tuple__impl {};

	template <size_t i, class T, class ...TrailingTypes>
	struct Tuple__impl : public TupleItem<i, T>, public Tuple__impl<i + 1, TrailingTypes...>
	{
		Tuple__impl(const T&& val, TrailingTypes...) : TupleItem<i, T>(val)
		{}
	};

	template <class ...Types>
	class Tuple : Tuple__impl<0, Types...>
	{
		static constexpr size_t size = sizeof...(Types);

	public:

		/*!
		 * @brief
		*/
		Tuple(const Types&&... values) : TupleItem(std::forward(values))
		{
		}
	};

}
