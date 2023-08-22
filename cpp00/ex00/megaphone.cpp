#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string args(argv[i]);
			for (unsigned long j = 0; j < args.length(); j++)
				std::cout << char(toupper(args[j]));
		}
	}
	std::cout << std::endl;
	return (0);
}