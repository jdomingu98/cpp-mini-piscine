#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(const AAnimal& aanimal);
        virtual ~AAnimal();

        AAnimal& operator = (const AAnimal& aanimal);

        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif