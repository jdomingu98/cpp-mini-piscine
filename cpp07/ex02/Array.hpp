#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int arraySize;
    public:
        Array(void);
        Array(unsigned int n);
        Array(Array const &o);
        ~Array(void);
        Array &operator=(Array const &o);
        T &operator[](unsigned int idx);
        unsigned int size(void) const;
        class OutOfRangeException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#include "Array.tpp"

#endif