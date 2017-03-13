#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::ofstream{ argv[1] }; // this line suffice to create the file
		std::cout << "The file '" << argv[1] << "' has been created.\n";
		return EXIT_SUCCESS;
	}
	std::cout << "Usage:\n\t" << argv[0] << " file_name\n";
	return EXIT_FAILURE;
}
