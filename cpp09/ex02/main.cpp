#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if(argc < 2)
        {
            std::cerr << "[ERROR] Too few arguments. Usage: ./PmergeMe <args>" << std::endl;
            return 1;
        }
        PmergeMe sortMerge(argc, argv);
        sortMerge.sort();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}