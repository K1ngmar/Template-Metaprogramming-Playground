
#include <stddef.h>

////////////////////////////
// true type / false type //
////////////////////////////

	template <class T, T v>
		struct integral_constant {
			static constexpr T value = v;
		};

	template <bool B>
		struct bool_constant : integral_constant<bool, B>{};

		struct true_type	: bool_constant<true>{};
		struct false_type	: bool_constant<false>{};

///////////
// Power //
///////////

template<const size_t nbr, const size_t power>
struct pow {
	static constexpr size_t value = nbr * pow<nbr, power -1>::value;
};

template<const size_t nbr>
struct pow<nbr, 0> {
	static constexpr size_t value = 1;
};

////////////
// is nbr //
////////////

template<const char c>
struct is_nbr : false_type {};

template<>
struct is_nbr<'0'> : true_type {};
template<>
struct is_nbr<'1'> : true_type {};
template<>
struct is_nbr<'2'> : true_type {};
template<>
struct is_nbr<'3'> : true_type {};
template<>
struct is_nbr<'4'> : true_type {};
template<>
struct is_nbr<'5'> : true_type {};
template<>
struct is_nbr<'6'> : true_type {};
template<>
struct is_nbr<'7'> : true_type {};
template<>
struct is_nbr<'8'> : true_type {};
template<>
struct is_nbr<'9'> : true_type {};

/////////////////////
// char to decimal //
/////////////////////


template<bool B, const char c>
struct __char_to_decimal_impl {
};

template<const char c>
struct __char_to_decimal_impl<true, c> {
	static constexpr int value = c - '0';
};


template <const char c>
struct char_to_decimal : __char_to_decimal_impl<is_nbr<c>::value, c> {
};

/////////////
// Metatoi //
/////////////

template <const char... nbr>
struct metatoi {
};

template <const char c>
struct metatoi<c> {
	static constexpr int value = char_to_decimal<c>::value;
};

template <const char c, const char... nbr>
struct metatoi<c, nbr...> {
	static constexpr int value = char_to_decimal<c>::value * pow<10, sizeof...(nbr)>::value + metatoi<nbr...>::value;
};
