
#pragma once

#include <stdlib.h>

namespace km
{
	template<size_t index, class Type>
	struct IndexType {};

	template <class Type>
	struct IndexType<0, Type>
	{
		using type = Type;
	};

	template <size_t indexToGet, class ...Types>
	struct GetNthTypeFromParameterPack__
	{};

	template <size_t index, class T, class ...TrailingTypes>
	struct GetNthTypeFromParameterPack__<index, T, TrailingTypes...> : public IndexType<index, T>, public GetNthTypeFromParameterPack__<index - 1, TrailingTypes...>
	{};

	template <size_t index, class T>
	struct GetNthTypeFromParameterPack__<index, T> : public IndexType<index, T>
	{
	};

	template <size_t indexToGet, class ...Types>
	using GetNthTypeFromParameterPack = GetNthTypeFromParameterPack__<indexToGet, Types...>::type;

	template <class ...Types>
	class Tuple;

	template <size_t indexToGet, class ...Types, class valueType = GetNthTypeFromParameterPack<indexToGet, Types...> >
	valueType& Get(Tuple<Types...>& tuple)
	{
		return tuple.template Get<indexToGet, valueType>();
	}
	
}
