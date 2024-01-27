#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <iomanip>
# include <algorithm>
# include <vector>
# include <deque>
# include <ctime>
//# include <chrono>

# define CYCLES_US CLOCKS_PER_SEC * 1e6

class PmergeMe
{
    private:
        PmergeMe();
        ~PmergeMe();
    public:
        PmergeMe(const PmergeMe& o);
        PmergeMe& operator=(const PmergeMe& o);
        static void sort(int argc, char **argv);
};

std::ostream& operator<<(std::ostream& os, std::vector<int>& deque);
std::ostream& operator<<(std::ostream& os, std::deque<int>& deque);

#endif