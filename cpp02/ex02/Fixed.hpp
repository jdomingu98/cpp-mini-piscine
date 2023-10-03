#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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

        bool operator > (const Fixed &f) const;
        bool operator < (const Fixed &f) const;
        bool operator >= (const Fixed &f) const;
        bool operator <= (const Fixed &f) const;
        bool operator == (const Fixed &f) const;
        bool operator != (const Fixed &f) const;

        Fixed& operator + (const Fixed& f) const;
        Fixed& operator - (const Fixed& f) const;
        Fixed& operator * (const Fixed& f) const;
        Fixed& operator / (const Fixed& f) const;

        //Los dos tipos de decremento e incremento

        int getRawBits() const;
        void setRawBits(int const raw);

        float toFloat() const;
        int toInt() const;

        // Las cuatro funciones min y max
};

std::ostream& operator << (std::ostream &o, const Fixed& f);

#endif