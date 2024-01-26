#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }
        BitcoinExchange btc;
        btc.getBitcoinValuesOnDate(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}