#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : year(0), month(0), day(0) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& o)
{
    *this = o;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o)
{
    database = o.database;
    return *this;
}

//--------------------------------------------------------------

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(SPECIAL_CHARS);
    size_t last = str.find_last_not_of(SPECIAL_CHARS);

    if (first == std::string::npos || last == std::string::npos)
        return str;
    return str.substr(first, last - first + 1);
}


void BitcoinExchange::readDatabase(std::string filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::string key;
    float value;
    
    std::getline(file, line, '\n');
    line = trim(line);
    if (line.compare("date,exchange_rate") != 0)
    {
        file.close();
        return;
    }
    while(std::getline(file, line, '\n'))
    {
        key = trim(line.substr(0, line.find(',')));
        try
        {
            std::string stringFloat = trim(line.substr(line.find(',') + 1));
            value = std::atof(stringFloat.c_str());
        }
        catch(std::out_of_range& e)
        {
            file.close();
            std::cerr << e.what() << std::endl;
        }
        database.insert(std::make_pair(key, value));
    }
    file.close();
}

bool inputOK(std::ifstream& file, std::string& line)
{
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }
    std::getline(file, line, '\n');
    line = trim(line);
    if (line.empty())
        return false;
    else if (line.compare("date | value") != 0)
        return false;
    return true;
}

bool BitcoinExchange::checkKey(std::string key)
{
    if (key.length() != 10 || key[4] != '-' || key[7] != '-')
        return false;
    this->year = std::atoi(key.substr(0, 4).c_str());
    this->month = std::atoi(key.substr(5, 2).c_str());
    this->day = std::atoi(key.substr(8, 2).c_str());

    if (this->month < 1 || this->month > 12)
        return false;
    if (this->day < 1 || this->day > 31)
        return false;
    if (this->month == 2 && this->day > 29)
        return false;
    if ((this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) && this->day > 30)
        return false;
    if (this->month == 2 && this->day == 29 && this->year % 4 != 0)
        return false;
    return true;
}

bool checkValue(std::string value)
{
    bool hasPoint = false;
    size_t i = value[0] == '-';
    
    if (value.empty())
        return false;
    while (i < value.length())
    {
        if (value[i] == '.' && !hasPoint)
        {
            hasPoint = true;
            i++;
            continue;
        }
        else if (value[i] == '.' && hasPoint)
            return false;
        if (!std::isdigit(value[i]))
            return false;
        i++;
    }
    return true;
}

void BitcoinExchange::printResults(std::string key, float value)
{
    std::map<std::string, float>::iterator it = database.find(key);
    std::string newKey = key;

    if (this->year < 2009)
        newKey = database.begin()->first;
    else if (this->year > 2022)
        newKey = database.rbegin()->first;
    else if (it == database.end())
        newKey = (--database.lower_bound(key))->first;

    float result = value * database[newKey];
    std::cout  << key << " => " << value << " = " << result << std::endl; 
}

void BitcoinExchange::getBitcoinValuesOnDate(std::string filename)
{
    readDatabase("data.csv");

    std::ifstream file(filename.c_str());
    std::string line;
    std::string key;
    std::string value;

    if (!inputOK(file, line))
    {
        file.close();
        return;
    }

    try
    {
        while (std::getline(file, line, '\n'))
        {
            key = trim(line.substr(0, line.find(" | ")));
            value = trim(line.substr(line.find(" | ") + 3));
            if (line.find(" | ") == std::string::npos)
                std::cerr << "Error: bad input => " << key << std::endl;
            else if (!checkKey(key))
                std::cerr << "Error: bad input => " << key << std::endl;
            else if (checkValue(value))
            {
                float valueFloat = std::atof(value.c_str());
                if (valueFloat < 0.0)
                    std::cerr << "Error: not a positive number." << std::endl;
                else if (valueFloat > 1000.0)
                    std::cerr << "Error: too large a number." << std::endl;
                else
                    printResults(key, valueFloat);
            }
        }    
    }
    catch (const std::out_of_range& e)
    {
        file.close();
        std::cerr << e.what() << std::endl;
    }
    file.close();
}
