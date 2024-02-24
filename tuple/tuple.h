
#pragma once

#include "tuple_get.h"

#include <stdlib.h>
#include <utility>

namespace km
{

	template <size_t i, class T>
	struct TupleItem
	{
		T item;

		TupleItem(T&& val) : item(std::forward<T>(val))
		{
		}

		TupleItem(const T& val) : item(val)
		{
		}
	};

	template <size_t i, class ...Ts>
	struct Tuple__impl {};

	// Base case
	template <size_t i, class T>
	struct Tuple__impl<i, T> : public TupleItem<i, T> {
	
		Tuple__impl(T&& val) : TupleItem<i, T>(std::forward<T>(val))
		{}

		Tuple__impl(const T& val) : TupleItem<i, T>(val)
		{}
	};

	template <size_t i, class T, class ...TrailingTypes>
	struct Tuple__impl<i, T, TrailingTypes...> : public TupleItem<i, T>, public Tuple__impl<i + 1, TrailingTypes...>
	{
		Tuple__impl(T&& val, TrailingTypes... trailingValues)
		: TupleItem<i, T>(std::forward<T>(val))
		, Tuple__impl<i + 1, TrailingTypes...>(std::forward<TrailingTypes>(trailingValues)...)
		{}

		Tuple__impl(const T& val, TrailingTypes... trailingValues)
		: TupleItem<i, T>(val)
		, Tuple__impl<i + 1, TrailingTypes...>(trailingValues...)
		{}
	};

	template <class ...Types>
	class Tuple : public Tuple__impl<0, Types...>
	{
		static constexpr size_t size = sizeof...(Types);

	public:

		template <size_t indexToGet, class valueType = GetNthTypeFromParameterPack<indexToGet, Types...> >
		valueType& Get()
		{
			return TupleItem<indexToGet, valueType>::item;
		}

		/*!
		 * @brief
		*/
		Tuple(Types&&... values) : Tuple__impl<0, Types...>(std::forward<Types>(values)...)
		{
		}

		Tuple(const Types&... values) : Tuple__impl<0, Types...>(values...)
		{
		}
	};

}
