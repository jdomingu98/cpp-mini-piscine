#include "easyfind.hpp"

#include <vector>
#include <list>

int main()
{
    try
    {
        std::cout << std::endl << "----------Vector----------" << std::endl;
        std::vector<int> vec;

        for(int i = 1; i <  8; i++)
            vec.push_back(i * 3);
        
        std::cout << "Elementos del vector: ";
        for(size_t j = 0; j < vec.size(); j++)
            std::cout << vec[j] << ' ';
        std::cout << std::endl;
    
        int n = 3;
        easyfind(vec, n);
    }
    catch(const OcurrenceNotFoundException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        std::cout << std::endl << "----------List------------" << std::endl;
        std::list<int> list;

        std::cout << "Elementos de la lista: ";
        for (int i = 0; i <= 20; i++) {
            list.push_back(i);
            std::cout << i << ' ';
        }
        std::cout << std::endl;
        std::list<int>::const_iterator iter_list;
        easyfind(list, 2);
        easyfind(list, 19);
        easyfind(list, 50);
    }
    catch(const OcurrenceNotFoundException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}