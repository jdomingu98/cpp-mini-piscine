#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Not arguments enough" << std::endl;
        return 1;
    }

    if (std::string(argv[1]).compare("debug") != 0 
        && std::string(argv[1]).compare("info") != 0
        && std::string(argv[1]).compare("warning") != 0
        && std::string(argv[1]).compare("error") != 0)
    {
        std::cout << "Incorrect Harl level mode" << std::endl;
        return 1;
    }

    Harl harl;

    harl.complain(argv[1]);
    return 0;
}