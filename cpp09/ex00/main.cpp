#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "[ERROR] Missing arguments. Usage: ./btc [file]" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    btc.takeData("data.csv");
    btc.takeInput(argv[1]);
    return 0;
}