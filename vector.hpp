#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector {
	public:
		Vector();
		Vector(int size);
		Vector(const Vector<T>& src);
		~Vector();

		Vector<T>& operator=(const Vector<T>& rhs);
		
}

#endif