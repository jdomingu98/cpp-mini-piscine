#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int value;
        static const int rawBits = 8;

    public:
        Fixed();
        Fixed(const Fixed& f);
        Fixed(const int v);
        Fixed(const float v);
        ~Fixed();

        Fixed& operator = (const Fixed& f);

        int getRawBits() const;
        void setRawBits(int const raw);

        float toFloat() const;
        int toInt() const;
};

std::ostream& operator << (std::ostream &o, const Fixed& f);

#endif