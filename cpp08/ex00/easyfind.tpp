#ifndef EASY_FIND_TPP
# define EASY_FIND_TPP

#include <algorithm>

template <typename T>
int easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw OcurrenceNotFoundException();
    return (*it);
}

template <typename T>
int easyfind(T const &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw OcurrenceNotFoundException();
    return (*it);
}

#endif