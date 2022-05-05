#ifndef VECTOR_ITERATOR
#define VECTOR_ITERATOR

#include "iterator_traits.hpp"

namespace ft {
	template< class T >
	class vector_iterator {
		typedef typename ft::iterator_traits<T>::value_type value_type;
		typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<T>::difference_type difference_type;
		typedef typename ft::iterator_traits<T>::pointer pointer;
		typedef typename ft::iterator_traits<T>::reference reference;

		private:
			T* ptr;

		public:
			// Constructors
			vector_iterator() : ptr(nullptr) {}
			vector_iterator(T* p) : ptr(p) {}

			// Operators
			reference operator*() const { return *ptr; }
			pointer operator->() const { return ptr; }
			

	}
}

#endif