#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define SPECIAL 4

# include <iostream>
# include <cstdlib>
# include <limits>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter	&operator=(const ScalarConverter &copy);
    public:
        static void convert(const std::string input);
};

#endif