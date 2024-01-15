#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

struct Data
{
    std::string s1;
    int n;
};

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &copy);
        Serializer	&operator=(const Serializer &copy);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif