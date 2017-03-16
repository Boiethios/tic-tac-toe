#include "glob-iterator.hpp"

#include <iostream>

int main(int argc, char ** argv)
{
	if (argc == 2)
	{
		for (auto file : dir_iterator_pattern{ argv[1] })
		{
			std::cout << file.path().string() << '\n';
		}
		return EXIT_SUCCESS;
	}
	std::cout << "Usage:\n\t" << argv[0] << " pattern\n";
	return EXIT_FAILURE;
}
