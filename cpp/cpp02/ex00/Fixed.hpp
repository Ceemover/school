#pragma once
#include <iostream>
//Used "Fixed &operator" instead of "void operator", because if "b = c", the assignation works, but it returns void into nothing.
//so, in case of "a = b = c", it will return void into a var a.
//getRawBits( void ) const; const because Getter that doesn't change anything

class Fixed {
private:
	int _fixed;
	static const int _fraction;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &ptr);
	Fixed &operator = (const Fixed &ptr);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


