#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {

    private:
        void debug();
        void info();
        void warning();
        void error();
    
    public:
        Harl();
        ~Harl();
        void complain(std::string level);

};

#endif