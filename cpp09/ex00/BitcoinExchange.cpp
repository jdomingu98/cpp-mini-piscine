#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& o)
{
    *this = o;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o)
{
    (void) o;
    return *this;
}

void BitcoinExchange::getBitcoinValuesonDate(std::string filename)
{
    
}