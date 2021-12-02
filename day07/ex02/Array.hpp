#ifndef EX02m_m_array_HPP
#define EX02m_m_array_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
private:
	T* m_array;
	unsigned int m_size;

public:
	Array<T>()
	        : m_array(), m_size() {
		m_array = 0;
		m_size = 0;
		m_array = new T();
	}
	explicit Array<T>(unsigned int n) 
	        : m_size()
	{
		m_size = n;
		m_array = new T[n];
		for (unsigned int i = 0; i < n; i++)
			m_array[i] = 0;
	}
	Array<T>(Array const &array)
	        : m_size()
	{
		if (array.m_array)
		{
			m_array = new T[array.m_size];
			for (unsigned int i = 0; i < array.m_size; i++)
				m_array[i] = array.m_array[i];
		}
		else
			m_array = 0;
		m_size = array.m_size;
	}
	~Array<T>()
	{
		if (m_array)
			delete[] m_array;
	}
	Array<T> & operator = (Array const & array)
	{
		if (m_array)
			delete[] m_array;
		if (array.m_array)
		{
			m_array = new T[array.m_size];
			for (unsigned int i = 0; i < array.m_size; i++)
				m_array[i] = array.m_array[i];
		}
		else
			m_array = 0;
		m_size = array.m_size;
		return *this;
	}
	T	& operator[](unsigned int i) const
	{
		if (!this->m_array || i >= size())
				throw std::invalid_argument("\x1B[31m****ERROR****\033[0m");
		return (this->m_array[i]);
	}

	unsigned int size() const
	{
		return m_size; }

	class MyCustomException : public std::exception
	{
	public:
		explicit MyCustomException(const std::string& err_string)
		:err_string(err_string){}
		virtual ~MyCustomException() throw(){}
		virtual const char* what() const throw();
	private:
		std::string err_string;
	};
};

template<typename T>
const char *Array<T>::MyCustomException::what() const throw() {
	return this->err_string.c_str();
}

template <typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & a)
{
	for (unsigned int i = 0; i < a.size(); i++)
		o << i << ":\t" << a[i] << " " << std::endl;
	return o;
}

#endif
