#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array() : _size(0)
{
	this->array = new T[0];
};

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	this->array = new T[n];
};

template <typename T>
Array<T>::~Array()
{
	delete [] this->array;
};

template <typename T>
Array<T>::Array(const Array& src) : _size(src.size())
{
    this->array = new T[src.size()];
    for (size_t i = 0; i < this->_size; i++)
        this->array[i] = src.array[i];
}

template <typename T>
Array<T> &		Array<T>::operator=( Array<T> const & rhs )
{
	if (this != &rhs)
	{
		delete [] this->array;
		this->array = new T[rhs.size()];
		this->_size = rhs.size();
		for (size_t i = 0; i < this->_size; i++)
			this->array[i] = rhs.array[i];
	}
	return (*this);
}

template <typename T>
T &		Array<T>::operator[](size_t i)
{
	if (i >= this->_size)
		throw std::out_of_range("Index out of range");
	return (this->array[i]);

};

template <typename T>
size_t Array<T>::size() const
{
	return (this->_size);
}