#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
    
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Span sp = Span(5);

        std::vector<int> values;
        values.push_back(6);
        values.push_back(3);
        values.push_back(17);
        values.push_back(9);
        values.push_back(11);

        sp.addNumber(values.begin(), values.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}