#pragma once
#include <iostream>
#include <cmath>

class Fixed {
private:
	int _fixed;
	static const int _fraction;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &ptr);
	Fixed(const int num);
	Fixed(const float num);
	Fixed &operator = (const Fixed &ptr);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

};
std::ostream &operator<<(std::ostream &out, Fixed const &ptr);


