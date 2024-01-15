#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &copy)
{
    (void) copy;
    return *this;
}

//----------------------------------------------

static bool isCharacter(const std::string input)
{
    return input.length() == 1 && !std::isdigit(input[0]);
}

static bool isInteger(const std::string input)
{
    int i = 0;
    if (input[i] == '+' || input[i] == '-')
        i++;
    while (input[i])
    {
        if (!std::isdigit(input[i]))
            return false;
        i++;
    }
    return true;
}

static bool isFloat(const std::string input)
{
    int i = 0;
    bool hasPoint = false;
    bool hasFloat = false;

    if (input[i] == '+' || input[i] == '-')
        i++;
    while (input[i])
    {
        if (input[i] == '.' && !hasPoint)
        {
            hasPoint = true;
            i++;
            continue ;
        }
        else if (input[i] == '.' && hasPoint)
            return false;
        else if (hasPoint && !hasFloat && input[i] == 'f')
        {
            hasFloat = true;
            if (input[i - 1] == '.')
                return false;
            i++;
            continue ;
        }
        else if ((hasPoint && hasFloat && input[i] == 'f')
                    || !std::isdigit(input[i]))
            return false;
        i++;
    }
    return hasFloat && hasPoint;
}

static bool isDouble(const std::string input)
{
    int i = 0;
    bool hasPoint = false;

    if (input[i] == '+' || input[i] == '-')
        i++;
    while (input[i])
    {
        if (input[i] == '.' && !hasPoint)
        {
            hasPoint = true;
            i++;
            continue ;
        }
        else if ((input[i] == '.' && hasPoint) || !std::isdigit(input[i]))
            return false;
        i++;
    }
    return hasPoint && input[input.size() -1] != '.';
}

static bool isSpecial(const std::string input)
{
    return input == "+inf" || input == "-inf" || input == "nan";
}

static bool isSpecialFloat(const std::string input)
{
    return input == "+inff" || input == "-inff" || input == "nanf";
}

static int getArgumentType(const std::string input)
{
    if (isCharacter(input))
        return CHAR;
    else if (isInteger(input))
        return INT;
    else if (isFloat(input))
        return FLOAT;
    else if (isDouble(input))
        return DOUBLE;
    else if (isSpecial(input) || isSpecialFloat(input))
        return SPECIAL;
    return -1;
}

static void castCharacter(const std::string input)
{
    if (input[0] < ' ' || input[0] > '~')
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << input[0] << "'" << std::endl;
    
    if (input[0] < std::numeric_limits<int>::min() || input[0] > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
    
    if (input[0] < std::numeric_limits<float>::min() || input[0] > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
    
    if (input[0] < std::numeric_limits<double>::min() || input[0] > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
}

static void castInteger(const std::string input)
{
    long long i = std::atoll(input.c_str());
    
    if (i < ' ' || i > '~')
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    
    if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static void castFloat(const std::string input)
{
    float f = std::atof(input.c_str());
    
    if (f < ' ' || f > '~')
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    
    if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    
    if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    
    if (f < std::numeric_limits<double>::min() || f > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void castDouble(const std::string input)
{
    double d = std::atof(input.c_str());
    
    if (d < ' ' || d > '~')
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    
    if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    
    if (d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

static void castSpecial(const std::string input)
{
    if (input == "+inf" || input == "+inff")
    {
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "+inff" << std::endl;
        std::cout << "double: " << "+inf" << std::endl;
    }
    else if (input == "-inf" || input == "-inff")
    {
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "-inff" << std::endl;
        std::cout << "double: " << "-inf" << std::endl;
    }
    else if (input == "nan" || input == "nanf")
    {
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "nanf" << std::endl;
        std::cout << "double: " << "nan" << std::endl;
    }
}

void ScalarConverter::convert(const std::string input) {

    int type = getArgumentType(input);

    switch (type)
    {
        case CHAR: castCharacter(input);
            break;
        case INT: castInteger(input);
            break;
        case FLOAT: castFloat(input);
            break;
        case DOUBLE: castDouble(input);
            break;
        case SPECIAL: castSpecial(input);
            break;
        default:
            throw std::exception();
            break;
    }
}