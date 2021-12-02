#ifndef EX00_WHATEVER_HPP
#define EX00_WHATEVER_HPP

#include <iostream>

template <typename T>
const T& max(const T& a, const T& b)
{
	return (a > b) ? a : b;
}

template <typename T>
const T& min(const T& a, const T& b)
{
	return (a < b) ? a : b;
}

template <typename T>
void swap(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}
//******CHECKLIST******
class Awesome
{
public:
	Awesome(void) : _n(0) {}
	Awesome(int n) : _n(n) {}
	Awesome &	operator=(Awesome &a) { _n = a._n; return *this; }
	bool		operator==(Awesome const &rhs) const {return (this->_n == rhs._n); }
	bool		operator!=(Awesome const &rhs) const {return (this->_n != rhs._n); }
	bool		operator>(Awesome const &rhs) const {return (this->_n > rhs._n); }
	bool		operator<(Awesome const &rhs) const {return (this->_n < rhs._n); }
	bool		operator>=(Awesome const &rhs) const {return (this->_n >= rhs._n); }
	bool		operator<=(Awesome const &rhs) const {return (this->_n <= rhs._n); }
	int get_n(void) const {return _n; }
private:
	int _n;
};

std::ostream & operator<<(std::ostream & o, Awesome const & a) { o << a.get_n(); return o; }

#endif
