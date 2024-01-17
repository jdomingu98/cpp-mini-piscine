#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <iostream>

class OcurrenceNotFoundException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("[ERROR] Ocurrence not found");
        }
};

# include "easyfind.tpp"

#endif