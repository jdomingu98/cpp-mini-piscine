#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int length, void (*f)(T const &))
{
    for (int i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void iter(T *array, int length, void (*f)(T &))
{
    for (int i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void printNumberMultiplyByTen(T const &i)
{
    std::cout << i * 10 << " ";
}

template <typename T>
void printNumberMultiplyByTwo(T &i)
{
    std::cout << i * 2 << " ";
}

#endif