
#include <stddef.h>

///////////
// Power //
///////////

template<const size_t nbr, const size_t power>
struct pow {
	static constexpr size_t val = nbr * pow<nbr, power -1>::val;
};

template<const size_t nbr>
struct pow<nbr, 0> {
	static constexpr size_t val = 1;
};

/////////////////////
// char to decimal //
/////////////////////

template <const char c>
struct char_to_decimal {
	static constexpr int value = c - '0';
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
	static constexpr int value = char_to_decimal<c>::value * pow<10, sizeof...(nbr)>::val + metatoi<nbr...>::value;
};
