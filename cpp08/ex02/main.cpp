#include "MutantStack.hpp"
#include <list>

int main()
{
    std::list<int> list;
    
    list.push_back(5);
    list.push_back(17);
    
    std::cout << list.back() << std::endl;
    
    list.pop_back();
    
    std::cout << list.size() << std::endl;
    
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(-42);
    list.push_back(0);
    
    std::list<int>::iterator itList = list.begin();
    std::list<int>::iterator iteList = list.end();
    
    ++itList;
    --itList;
    while (itList != iteList)
    {
        std::cout << *itList << std::endl;
        ++itList;
    }
    std::list<int> sList(list);

    std::cout << "--------------------------------------------------" << std::endl;

    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(-42);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);


    return 0;
}