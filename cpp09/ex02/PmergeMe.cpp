#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& o)
{
    *this = o;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& o)
{
    return *this;
}