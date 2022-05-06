#ifndef VECTOR_ITERATOR
# define VECTOR_ITERATOR

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
			T* _ptr;

		public:
			// Constructors / Destructor
			vector_iterator() : _ptr(NULL) {}
			vector_iterator(T* p) : _ptr(p) {}
			~vector_iterator() {}

			// Operators
			reference operator*() const { return *_ptr; }
			pointer operator->() const { return _ptr; }
			vector_iterator& operator++() {
				++_ptr;
				return *this;
			}
			vector_iterator operator++(int) {
				return vector_iterator(_ptr++);
			}
			vector_iterator& operator--() {
				--_ptr;
				return *this;
			}
			vector_iterator operator--(int) {
				return vector_iterator(_ptr--);
			}
			reference operator[](difference_type n) {
				return _ptr[n];
			}
			vector_iterator& operator+=(difference_type n) {
				_ptr += n;
				return *this;
			}
			vector_iterator operator+(difference_type n) {
				return vector_iterator(_ptr + n);
			}
			vector_iterator& operator-=(difference_type n) {
				_ptr -= n;
				return *this;
			}
			vector_iterator operator-(difference_type n) {
				return vector_iterator(_ptr - n);
			}
			const T& base() const {
				return ptr;
			}
			bool operator==(const vector_iterator& rhs) {
				return _ptr == rhs.base();
			}
			

	};
}

#endif