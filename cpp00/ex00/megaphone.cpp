#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
			for (int j = 0; j < ((std::string) argv[i]).length(); j++)
				std::cout << toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (0);
}