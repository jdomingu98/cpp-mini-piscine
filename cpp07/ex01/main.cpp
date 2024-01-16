#include "iter.hpp"



int main(void)
{

    int int_array[5] = {1, 2, 3, 4, 5};

    std::cout << "int_array before iter:" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << int_array[i] << " ";
    std::cout << std::endl;
    iter(int_array, 5, &printNumberMultiplyByTen);
    std::cout << std::endl;
    std::cout << "int_array after iter:" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << int_array[i] << " ";
    std::cout << std::endl;
    return (0);
}