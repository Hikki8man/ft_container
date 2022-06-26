#ifndef VECTOR_ITERatorATOR_HPP
#define VECTOR_ITERatorATOR_HPP

#include "../utils/iterator_traits.hpp"

namespace ft {

	template< class _Iterator >
	class vector_iterator {

		protected:
			_Iterator _current;

			typedef ft::iterator_traits<_Iterator> traits_type;

		public:
			typedef typename traits_type::iterator_category iterator_category;
			typedef typename traits_type::value_type value_type;
			typedef typename traits_type::difference_type difference_type;
			typedef typename traits_type::reference reference;
			typedef typename traits_type::pointer pointer;


		public:
			// Constructors / Destructor
			vector_iterator() : _current(_Iterator()) {}

			vector_iterator(const _Iterator& p) : _current(p) {}
			
			template<typename _Iter>
				vector_iterator(const vector_iterator<_Iter>& other) : _current(other.base()) {}

			vector_iterator& operator=(const vector_iterator& other) {
				_current = other._current;
				return *this;
			}
			~vector_iterator() {}

			const _Iterator& base() const {
				return _current;
			}

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
			vector_iterator operator+(difference_type n) const {
				return vector_iterator(_current + n);
			}
			
	};
	
	template< class IteratorL, class IteratorR >
	bool operator==(const vector_iterator<IteratorL>& lhs, const vector_iterator<IteratorR>& rhs) {
		return lhs.base() == rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator!=(const vector_iterator<IteratorL>& lhs, const vector_iterator<IteratorR>& rhs) {
		return lhs.base() != rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator<(const vector_iterator<IteratorL>& lhs, const vector_iterator<IteratorR>& rhs) {
		return lhs.base() < rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator>(const vector_iterator<IteratorL>& lhs, const vector_iterator<IteratorR>& rhs) {
		return lhs.base() > rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator<=(const vector_iterator<IteratorL>& lhs, const vector_iterator<IteratorR>& rhs) {
		return lhs.base() <= rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator>=(const vector_iterator<IteratorL>& lhs, const vector_iterator<IteratorR>& rhs) {
		return lhs.base() >= rhs.base();
	}
	template< class Iterator>
	typename vector_iterator<Iterator>::difference_type operator-(const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs) {
		return lhs.base() - rhs.base();
	}	
	template< class Iterator>
	typename vector_iterator<Iterator>::difference_type operator+(const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs) {
		return lhs.base() + rhs.base();
	}
}

#endif