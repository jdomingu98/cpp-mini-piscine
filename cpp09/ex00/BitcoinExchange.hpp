#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <algorithm>
# include <iomanip>

class BitcoinExchange
{
    private:
        BitcoinExchange();
        ~BitcoinExchange();
    public:
        BitcoinExchange(const BitcoinExchange& o);
        BitcoinExchange& operator=(const BitcoinExchange& o);
        static void getBitcoinValuesonDate(std::string filename);
};

#endif