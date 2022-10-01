/* ************************************************************************** */
/*                                                                            */
/*              ____        _      __      __  ___      __  __                */
/*             / __ \__  __(_)____/ /__   /  |/  /___ _/ /_/ /_  _____        */
/*            / / / / / / / / ___/ //_/  / /|_/ / __ `/ __/ __ \/ ___/        */
/*           / /_/ / /_/ / / /__/ ,<    / /  / / /_/ / /_/ / / (__  )         */
/*           \___\_\__,_/_/\___/_/|_|  /_/  /_/\__,_/\__/_/ /_/____/          */
/*                                                                            */
/*                   Kingmar  |  https://github.com/K1ngmar                   */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_MATHS_ADDITION_HPP
# define QUICK_MATHS_ADDITION_HPP

/////////////
// Int sum //
/////////////

	// base
	template <int...>
		struct int_sum {};

	// single value
	template <int val>
	struct int_sum<val> {
		const static int value = val;
	};

	// recursive addition
	template <int val, int ...list>
	struct int_sum<val, list...> {
		const static int value = val + int_sum<list...>::value;
	};

/////////////////
// Generic sum //
/////////////////

	template <auto ...args>
	struct __sum
	{
		static const auto value = (0 + ... + args);
	};

	// alias decleration
	template<auto ...args>
		auto sum = __sum<args...>::value;

#endif
