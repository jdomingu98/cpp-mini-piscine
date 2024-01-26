#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& o)
{
    *this = o;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& o)
{
    (void) o;
    return *this;
}

std::ostream& operator<<(std::ostream& os, std::vector<int>& vec)
{
    std::vector<int>::iterator it;
    
    for (it = vec.begin(); it != vec.end(); it++)
        os << *it << " ";
    return os;
}

std::ostream& operator<<(std::ostream& os, std::deque<int>& deque)
{
    std::deque<int>::iterator it;
    
    for (it = deque.begin(); it != deque.end(); it++)
        os << *it << " ";
    return os;
}

bool isNumber(std::string num)
{
    if (num.empty() || num[0] == '-' || (num[0] == '+' && num.length() == 1))
        return false;
        
    size_t i = num[0] == '+';

    while (i < num.length())
    {
        if (!std::isdigit(num[i]))
            return false;
        i++;
    }
    return true;
}

template <typename T>
bool isSorted(T& list)
{
    if (list.size() == 1 || list.size() == 0)
        return true;
    
    typename T::iterator it;
    
    for (it = list.begin() ; it != list.end(); it++) {
        if (*it >= *(it + 1))
            return false;
    }
    return true;
}

template<typename T>
void merge(T &list, int left, int mid, int right)
{
    T leftSide(mid - left + 1);
    T rightSide(right - mid);

    typename T::iterator leftIt = leftSide.begin();
    typename T::iterator rightIt = rightSide.begin();
    
    for (int i = left; i < mid + 1; i++)
    {
        *leftIt = list[i];
        leftIt++;
    }
    
    for (int i = mid; i < right; i++)
    {
        *rightIt = list[i + 1];
        rightIt++;        
    }

    leftIt = leftSide.begin();
    rightIt = rightSide.begin();
    
    int i = left;
    
    while (leftIt != leftSide.end() && rightIt != rightSide.end())
        list.at(i++) = *leftIt <= *rightIt ? *leftIt++ : *rightIt++;
    
    while (leftIt != leftSide.end())
        list[i++] = *leftIt++;

    while (rightIt != rightSide.end())
        list[i++] = *rightIt++;
}

template<typename T>
T sortCollection(T list)
{
    if (isSorted(list))
        return list;
        
    bool odd = list.size() % 2 == 1;
    int lastNumber = list.size() % 2 == 1 ? list.back() : 0;
    
    if (odd)
        list.pop_back();

    int len = list.size();
    T auxList(list);

    for (int currSize = 1; currSize < len; currSize *= 2) {
        for (int left = 0; left < len; left += 2 * currSize) {
            int mid = std::min(left + currSize - 1, len - 1);
            int right = std::min(left + 2 * currSize - 1 , len - 1);
            merge(auxList, left, mid, right);
        }
    }
    
    typename T::iterator it;
    
    if (odd)
    {
        it = std::upper_bound(auxList.begin(), auxList.end(), lastNumber);
        auxList.insert(it, lastNumber);
    }
    return auxList;
}

void PmergeMe::sort(int argc, char **argv)
{
    std::vector<int> vectorList;
    std::deque<int> dequeList;
    std::clock_t clockCycles;
    long number;
    
    for (int i = 1; i < argc; i++) {
        if (!isNumber(argv[i]))
            throw std::invalid_argument("[ERROR] Invalid argument. Usage: ./PmergeMe <list of positive numbers>");
        number = std::strtol(argv[i], NULL, 10);
        vectorList.push_back(number);
        dequeList.push_back(number);
    }

    std::cout << "Before: " << vectorList << std::endl;

    clockCycles = std::clock();
    vectorList = sortCollection(vectorList);
    clockCycles = std::clock() - clockCycles;


    std::cout << "After: " << vectorList << std::endl;

    std::cout << "Time to process a range of " << vectorList.size() << " elements with std::vector<int> : ";
    std::cout << static_cast<double>(clockCycles) / CYCLES_US << " us" << std::endl;

    //--------------------------------------------------------------------------------

    clockCycles = std::clock();
    dequeList = sortCollection(dequeList);
    clockCycles = std::clock() - clockCycles;

    std::cout << "Time to process a range of " << dequeList.size() << " elements with std::deque<int> : ";
    std::cout << static_cast<double>(clockCycles) / CYCLES_US << " us" << std::endl;
}