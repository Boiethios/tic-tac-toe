#include <iostream>

#include "string-stuff.hpp"

#define STRINGIFY(a) STRINGIFY_(a)
#define STRINGIFY_(a) #a

#define MY_ASSERT(CONDITION) \
	do { \
		if (!(CONDITION)) \
			std::cout << "Error: assertion `" STRINGIFY(CONDITION) "` failed.\n"; \
	} while (0)


int main()
{
	std::string lt{ "  hello " };
	MY_ASSERT(left_trim("  hello ") == "hello ");
	MY_ASSERT(left_trim(std::string{ " hello  " }) == "hello  ");
	MY_ASSERT(left_trim(lt) == "hello ");

	std::string rt{ "  hello " };
	MY_ASSERT(right_trim("  hello ") == "  hello");
	MY_ASSERT(right_trim(std::string{ " hello  " }) == " hello");
	MY_ASSERT(right_trim(rt) == "  hello");

	std::string t{ "  hello " };
	MY_ASSERT(trim("  hello  ") == "hello");
	MY_ASSERT(trim(std::string{ " hello  " }) == "hello");
	MY_ASSERT(trim(rt) == "hello");
}
