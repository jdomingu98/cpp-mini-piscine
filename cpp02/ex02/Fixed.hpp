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

        Fixed operator + (const Fixed& f) const;
        Fixed operator - (const Fixed& f) const;
        Fixed operator * (const Fixed& f) const;
        Fixed operator / (const Fixed& f) const;

        Fixed& operator ++ ();
        Fixed operator ++ (int);
        Fixed& operator -- ();
        Fixed operator -- (int);


        int getRawBits() const;
        void setRawBits(int const raw);

        float toFloat() const;
        int toInt() const;

        static Fixed &min(Fixed &f1, Fixed &f2);
        static const Fixed &min(const Fixed &f1, const Fixed &f2);
        static Fixed &max(Fixed &f1, Fixed &f2);
        static const Fixed &max(const Fixed &f1, const Fixed &f2);

};

std::ostream& operator << (std::ostream &o, const Fixed& f);

#endif