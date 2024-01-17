#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span {

    private:
        std::vector<int> *v;
        Span();
    public:
        class FullSpanException;
        class NotEnoughNumbersException;
        Span(unsigned int n);
        Span(Span const &o);
        ~Span();
        Span &operator=(Span const &o);
        void addNumber(int n);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        unsigned int shortestSpan();
        unsigned int longestSpan();
};

#endif