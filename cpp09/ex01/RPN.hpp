#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
    private:
        RPN();
        RPN(const RPN &o);
        ~RPN();
        RPN &operator=(const RPN &o);
    public:
        class ParseException;
        class DivideByZeroException;
        static void run(std::string input);
};

#endif