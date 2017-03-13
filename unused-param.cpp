#include <experimental/filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;

/// rvalue reference to lvalue reference
template<typename T>
constexpr T & unused_ref(T && rvalue) noexcept
{
	return rvalue;
}

/// rvalue reference to C pointer
template<typename T>
constexpr T * unused_ptr(T && rvalue) noexcept
{
	return &rvalue;
}

std::ostream & operator<<(std::ostream & os, fs::file_time_type ftt)
{
	std::time_t time{ fs::file_time_type::clock::to_time_t(ftt) };
	return os << std::asctime(std::localtime(&time));
}

int main()
{
	auto time{ fs::last_write_time(__FILE__, unused_ref(std::error_code{})) }; // we do not care about the error code

	std::cout << time;
}
