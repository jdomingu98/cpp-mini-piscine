#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
        {
            std::cout << "[ERROR] Missing arguments. Usage: ./btc <file>" << std::endl;
            return 1;
        }
        BitcoinExchange::getBitcoinValuesonDate(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}