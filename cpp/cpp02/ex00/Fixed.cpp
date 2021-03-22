#include "Fixed.hpp"
//if static changes, it changes for every object in the class

const int Fixed::_fraction = 8;

Fixed::Fixed(const Fixed &ptr){
	std::cout << "Copy constructor called" << std::endl;
	_fixed = ptr._fixed;
}

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	_fixed = 0;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &ptr){
	std::cout << "Assignation operator called" << std::endl;
	_fixed = ptr._fixed;
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called"  << std::endl;
	return _fixed;
}

void Fixed::setRawBits(int const raw) {
	_fixed = raw;
}