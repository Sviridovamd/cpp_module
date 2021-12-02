#ifndef EX01_ITER_HPP
#define EX01_ITER_HPP

template<typename T, typename TT>
void iter(T* const array, TT const & size, void(*fx)(T const &))
{
	for (int i = 0; i < size; i++)
		fx(array[i]);
}

template<typename T>
T *createArray(T start, const int &size)
{
	T *ret = new T[size];
	for (int i = 0; i < size; i++)
		ret[i] = start++;
	return ret;
}

template <typename T>
void print(T const &t)
{
	std::cout << "this:\t";
	std::cout << t << std::endl;
}
//CHECKLIST
class Awesome
{
public:
	Awesome(void) : _n(42) { return ;}
	int get(void) const {return this->_n; }
private:
	int _n;
};

std::ostream & operator<<(std::ostream & o, Awesome const & rhs) { o << rhs.get(); return o; }
template <typename T>
void print_a(T const &x) {std::cout<<x<<std::endl;return;}

#endif
