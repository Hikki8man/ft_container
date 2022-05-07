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
			T* _current;

		public:
			// Constructors / Destructor
			vector_iterator() : _current(NULL) {}
			vector_iterator(T* p) : _current(p) {}
			~vector_iterator() {}

			// Operators
			reference operator*() const { return *_current; }
			pointer operator->() const { return _current; }
			vector_iterator& operator++() {
				++_current;
				return *this;
			}
			vector_iterator operator++(int) {
				return vector_iterator(_current++);
			}
			vector_iterator& operator--() {
				--_current;
				return *this;
			}
			vector_iterator operator--(int) {
				return vector_iterator(_current--);
			}
			reference operator[](difference_type n) {
				return _current[n];
			}
			vector_iterator& operator+=(difference_type n) {
				_current += n;
				return *this;
			}
			vector_iterator operator+(difference_type n) {
				return vector_iterator(_current + n);
			}
			vector_iterator& operator-=(difference_type n) {
				_current -= n;
				return *this;
			}
			vector_iterator operator-(difference_type n) {
				return vector_iterator(_current - n);
			}
			const T& base() const {
				return ptr;
			}
			bool operator==(const vector_iterator& rhs) {
				return _current == rhs.base();
			}
			

	};
}

#endif