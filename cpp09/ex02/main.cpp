#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if(argc < 2)
        {
            std::cerr << "[ERROR] Too few arguments. Usage: ./PmergeMe <list of integer positive numbers>" << std::endl;
            return 1;
        }
        PmergeMe::sort(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}