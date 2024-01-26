#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <algorithm>

# define SPECIAL_CHARS " \t\n\r\f\v"

class BitcoinExchange
{
    private:
        std::map<std::string, float> database;
        int year;
        int month;
        int day;
        void readDatabase(std::string filename);
        bool checkKey(std::string key);
        void printResults(std::string key, float value);
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& o);
        BitcoinExchange& operator=(const BitcoinExchange& o);
        void getBitcoinValuesOnDate(std::string filename);
};

#endif