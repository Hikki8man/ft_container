#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

template <class T>
class Vector {
	public:
		Vector() : _size(0), _capacity(0), _data(NULL) {};
		Vector(size_t size, const T & value) {
			_size = size;
			_capacity = size;
			_data = new T[size];
			for (size_t i = 0; i < size; i++)
				_data[i] = value;
		};
		Vector(const Vector<T>& src);
		~Vector();

		Vector<T>& operator=(const Vector<T>& rhs);
	private:
		T* _data;
		size_t _size;
		size_t _capacity;
		
};

#endif