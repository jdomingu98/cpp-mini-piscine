#include "RPN.hpp"

class RPN::ParseException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("[ERROR] Invalid symbol found");
        }
};

class RPN::DivideByZeroException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("[ERROR] Cannot divide by zero");
        }
};

RPN::RPN() {}

RPN::RPN(const RPN &o)
{
    *this = o;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &o)
{
    (void) o;
    return (*this);
}

bool isOperation(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool parseNumbers(std::string input)
{
    size_t pos = 0;
    std::string token;

    while ((pos = input.find(' ')) != std::string::npos) {
        token = input.substr(0, pos);
        input.erase(0, pos + 1);
        if (std::isdigit(token[0]) && token.length() > 1)
            return false;
    }
    return true;
}

void RPN::run(std::string input)
{
    std::stack<int> stack;

    if (!parseNumbers(input))
        throw ParseException();
    for (unsigned long i = 0; i < input.length(); i++)
    {
        if (!isOperation(input[i]) && !std::isdigit(input[i]) && input[i] != ' ')
            throw ParseException();
        if (isOperation(input[i]))
        {
            int num2 = stack.top();
            stack.pop();
            int num1 = stack.top();
            stack.pop();
            
            if (input[i] == '+')
                stack.push(num1 + num2);
            else if (input[i] == '-')
                stack.push(num1 - num2);
            else if (input[i] == '*')
                stack.push(num1 * num2);
            else if (input[i] == '/')
            {
                if (num2 == 0)
                    throw DivideByZeroException();
                stack.push(num1 / num2);
            }
        }
        else if (std::isdigit(input[i]))
            stack.push(static_cast<int>(input[i] - '0'));
    }
    std::cout << stack.top() << std::endl;
}