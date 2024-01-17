#include "Span.hpp"
#include <cstdlib>
#include <cmath>

class Span::FullSpanException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "[ERROR] Span is full";
        }
};

class Span::NotEnoughNumbersException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "[ERROR] Not enough numbers in Span";
        }
};

Span::Span() : v(new std::vector<int>())
{
    (*this->v).reserve(0);
}

Span::Span(unsigned int n) : v(new std::vector<int>())
{
    (*this->v).reserve(n);
}

Span::Span(Span const &o)
{
    *this = o;
}

Span::~Span()
{
    delete this->v;
}

Span &Span::operator=(Span const &o)
{
    this->v = o.v;
    return *this;
}

void Span::addNumber(int n)
{
    if (this->v->size() == this->v->capacity())
        throw Span::FullSpanException();

    this->v->push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->v->size() + std::distance(begin, end) > this->v->capacity())
        throw Span::FullSpanException();

    std::vector<int>::iterator it = this->v->begin();
    std::advance(it, this->v->size());

    this->v->insert(it, begin, end);
}


unsigned int Span::shortestSpan()
{
    if (this->v->size() < 2)
        throw Span::NotEnoughNumbersException();

    std::vector<int> tmp = *this->v;
    int min = INT_MAX;
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
    {
        min = std::abs(*(it + 1) - *it) < min ? std::abs(*(it + 1) - *it) : min;
    }
    return (min == INT_MAX) ? 0 : min;
}

unsigned int Span::longestSpan()
{
    if (this->v->size() < 2)
        throw Span::NotEnoughNumbersException();

    std::vector<int> tmp = *this->v;
    int max = INT_MIN;
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
        max = std::abs(*(it + 1) - *it) > max ? std::abs(*(it + 1) - *it) : max;
    return (max == INT_MIN) ? 0 : max;
}