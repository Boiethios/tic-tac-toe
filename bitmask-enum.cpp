#include <iostream>

#include "bitmask-enum.hpp"

enum class flag_options
{
	NONE   = 0,
	FIRST  = bitmask(0),
	SECOND = bitmask(1),
	THIRD  = bitmask(2),
};

/* Activate the logical operators overload for this enum */
template<> struct is_bitmask_enum<flag_options> : std::true_type {};

/* Usage */
int main()
{
	auto options = flag_options::NONE;
  
	options |= flag_options::SECOND;
	if (is_flag_on(options, flag_options::FIRST))
	{
		std::cout << "FIRST flag is set\n";
	}
	if (is_flag_on(options, flag_options::SECOND))
	{
		std::cout << "SECOND flag is set\n";
	}
}
