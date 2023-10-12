#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed::Fixed(const int v)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = v << this->rawBits;
}

Fixed::Fixed(const float v)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(v * (1 << this->rawBits));
}

Fixed& Fixed::operator = (const Fixed& f)
{
    std::cout << "Assignation operator called" << std::endl;
    this->value = f.value;
    return *this;
}

bool Fixed::operator > (const Fixed& f) const
{
    return this->toFloat() > f.toFloat();
}

bool Fixed::operator < (const Fixed& f) const
{
    return this->toFloat() < f.toFloat();
}

bool Fixed::operator >= (const Fixed& f) const
{
    return this->toFloat() >= f.toFloat();
}

bool Fixed::operator <= (const Fixed& f) const
{
    return this->toFloat() <= f.toFloat();
}

bool Fixed::operator == (const Fixed& f) const
{
    return this->toFloat() == f.toFloat();
}

bool Fixed::operator != (const Fixed& f) const
{
    return this->toFloat() != f.toFloat();
}

Fixed Fixed::operator + (const Fixed& f) const
{
    return Fixed(this->toFloat() + f.toFloat());
}

Fixed Fixed::operator - (const Fixed& f) const
{
    return Fixed(this->toFloat() - f.toFloat());
}

Fixed Fixed::operator * (const Fixed& f) const
{
    return Fixed(this->toFloat() * f.toFloat());
}

Fixed Fixed::operator / (const Fixed& f) const
{
    return Fixed(this->toFloat() / f.toFloat());
}

Fixed& Fixed::operator ++ ()
{
    ++value;
    return *this;
}

Fixed Fixed::operator ++ (int)
{
    Fixed aux(*this);
    value++;
    return aux;
}

Fixed& Fixed::operator -- ()
{
    --value;
    return *this;
}

Fixed Fixed::operator -- (int)
{
    Fixed aux(*this);
    value--;
    return aux;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float Fixed::toFloat() const
{
    return float(this->value) / (1 << rawBits);
}

int Fixed::toInt() const
{
    return this->value >> this->rawBits;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
    return f1 < f2 ? f1 : f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
    return f1.getRawBits() < f2.getRawBits() ? f1 : f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
    return f1 > f2 ? f1 : f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
    return f1.getRawBits() > f2.getRawBits() ? f1 : f2;
}

std::ostream& operator << (std::ostream &o, const Fixed& f)
{
    return o << f.toFloat();
}