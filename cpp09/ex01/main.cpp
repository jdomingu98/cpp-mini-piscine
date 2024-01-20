#include "RPN.hpp"

int main(int argc, const char **argv)
{
    try
    {
        if (argc == 1)
        {
            std::cout << "[ERROR] Missing args. Usage ./RPN <expression>" << std::endl;
            return 1;
        }
        RPN::run(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}