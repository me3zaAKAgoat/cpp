#pragma once

#include <cstddef>

template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array( Array const & src );
		Array &		operator=( Array const & rhs );
		T &		operator[](size_t i);
		size_t size(void) const;
	private:
		T* array;
		size_t _size;
};

#include "Array.tpp"
