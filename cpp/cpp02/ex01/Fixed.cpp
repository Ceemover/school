#include "Fixed.hpp"

const int Fixed::_fraction = 8;

Fixed::Fixed(const Fixed &ptr){
	std::cout << "Copy constructor called" << std::endl;
	*this = ptr;
}

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	_fixed = 0;
}

Fixed::Fixed(const int num){
	_fixed = (num << Fixed::_fraction);
	std::cout << "Int constructor called" << std::endl;
}

// if num == 5.6 :
//(1 << this->_fraction) == 100000000_2 == 256_10
//5.6 * 256 = 1433.6 = 1434 (stored as int)

Fixed::Fixed(const float num){
	this->_fixed = roundf(num * (1 << this->_fraction));
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat( void ) const {
	return (float)this->_fixed / (float)(1 << this->_fraction);
}

int Fixed::toInt( void ) const {
	return (this->_fixed >> this->_fraction);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &ptr){
	std::cout << "Assignation operator called" << std::endl;
	this->_fixed = ptr._fixed;
	return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called"  << std::endl;
	return _fixed;
}

void Fixed::setRawBits( int const raw ) {
	_fixed = raw;
}

std::ostream &operator<<(std::ostream &out, Fixed const &ptr)
{
	out << ptr.toFloat();
	return (out);
}
