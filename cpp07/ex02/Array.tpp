#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : array(new T[0]), arraySize(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), arraySize(n) {}

template <typename T>
Array<T>::Array(Array const &o)
{
    *this = o;
}

template <typename T>
Array<T>::~Array(void)
{
    delete []array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &o)
{
    delete [] array;
    arraySize = o.arraySize;
    array = new T[o.arraySize];
    for (unsigned int i = 0; i < arraySize; i++)
        array[i] = o.array[i];
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int idx)
{
    return idx >= arraySize ? throw OutOfRangeException() : array[idx];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return arraySize;
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw()
{
    return "[ERROR] Index out of range";
}

#endif