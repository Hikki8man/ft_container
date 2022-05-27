#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

	template< class _Iterator >
	class random_access_iterator {

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
			random_access_iterator() : _current(_Iterator()) {}
			random_access_iterator(const _Iterator& p) : _current(p) {}
			template<typename _Iter>
				random_access_iterator(const random_access_iterator<_Iter>& other) : _current(other.base()) {}
				random_access_iterator& operator=(const random_access_iterator& other) {
					_current = other._current;
					return *this;
				}
			~random_access_iterator() {}

			const _Iterator& base() const {
				return _current;
			}

			// Operators
			reference operator*() const { return *_current; }
			pointer operator->() const { return _current; }
			random_access_iterator& operator++() {
				++_current;
				return *this;
			}
			random_access_iterator operator++(int) {
				return random_access_iterator(_current++);
			}
			random_access_iterator& operator--() {
				--_current;
				return *this;
			}
			random_access_iterator operator--(int) {
				return random_access_iterator(_current--);
			}
			reference operator[](difference_type n) {
				return _current[n];
			}
			random_access_iterator& operator+=(difference_type n) {
				_current += n;
				return *this;
			}
			random_access_iterator operator+(difference_type n) {
				return random_access_iterator(_current + n);
			}
			random_access_iterator& operator-=(difference_type n) {
				_current -= n;
				return *this;
			}
			random_access_iterator operator-(difference_type n) {
				return random_access_iterator(_current - n);
			}
			random_access_iterator operator+(difference_type n) const {
				return random_access_iterator(_current + n);
			}
			
	};
	
	template< class IteratorL, class IteratorR >
	bool operator==(const random_access_iterator<IteratorL>& lhs, const random_access_iterator<IteratorR>& rhs) {
		return lhs.base() == rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator!=(const random_access_iterator<IteratorL>& lhs, const random_access_iterator<IteratorR>& rhs) {
		return lhs.base() != rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator<(const random_access_iterator<IteratorL>& lhs, const random_access_iterator<IteratorR>& rhs) {
		return lhs.base() < rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator>(const random_access_iterator<IteratorL>& lhs, const random_access_iterator<IteratorR>& rhs) {
		return lhs.base() > rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator<=(const random_access_iterator<IteratorL>& lhs, const random_access_iterator<IteratorR>& rhs) {
		return lhs.base() <= rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator>=(const random_access_iterator<IteratorL>& lhs, const random_access_iterator<IteratorR>& rhs) {
		return lhs.base() >= rhs.base();
	}
	template< class Iterator>
	typename random_access_iterator<Iterator>::difference_type operator-(const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs) {
		return lhs.base() - rhs.base();
	}	
	template< class Iterator>
	typename random_access_iterator<Iterator>::difference_type operator+(const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs) {
		return lhs.base() + rhs.base();
	}
}

#endif