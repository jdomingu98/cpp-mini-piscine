#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "[ERROR] Missing or too many args. Usage ./scalarConverter [input]" << std::endl;
        return 1;
    }
    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch (std::exception& e)
    {
        std::cerr << "[ERROR] Unknown type to convert" << std::endl;
    }    
    return 0;
}