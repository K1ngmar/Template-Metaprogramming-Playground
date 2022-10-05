

// template<const char c>
// struct is_white_space {
// 	static constexpr bool value = (c >= 9 && c <= 13) || c == ' ';
// };

// template <bool b, const char c>
// struct __atoi {
// 	static constexpr int value = 1; // do nothing
// };

template <const char c>
struct char_to_decimal {
	static constexpr int value = c - '0';
};

template <const char ...nbr>
struct metatoi {
};

template <const char c>
struct metatoi<c> {
	static constexpr int value = char_to_decimal<c>::value;
};

template <const char c, const char ...nbr>
struct metatoi<c, nbr...> {
	static constexpr int value = char_to_decimal<c>::value * (10 * sizeof...(nbr)) + metatoi<nbr...>::value;
};
