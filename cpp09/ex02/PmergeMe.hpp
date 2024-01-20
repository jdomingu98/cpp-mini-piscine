#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <iostream>

class PmergeMe
{
    private:
        PmergeMe();
        ~PmergeMe();
    public:
        PmergeMe(const PmergeMe& o);
        PmergeMe& operator=(const PmergeMe& o);
};

#endif