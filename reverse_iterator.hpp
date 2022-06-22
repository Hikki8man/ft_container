#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
	template< class _Iterator >
	class reverse_iterator {
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
			reverse_iterator() : _current() {}
			reverse_iterator(_Iterator x) : _current(x) {}
			template<typename _Iter>
				reverse_iterator(const reverse_iterator<_Iter>& other) : _current(other.base()) {}
				reverse_iterator& operator=(const reverse_iterator& other) {
					_current = other._current;
					return *this;
				}
			~reverse_iterator() {}

			const _Iterator& base() const {
				return _current;
			}

			// Operators
			reference operator*() const {
				_Iterator tmp = _current;
				return *(--tmp);
			}
			pointer operator->() const {
				return &operator*();
			}
			reverse_iterator& operator++() {
				--_current;
				return *this;
			}
			reverse_iterator operator++(int) {
				return reverse_iterator(_current--);
			}
			reverse_iterator& operator--() {
				++_current;
				return *this;
			}
			reverse_iterator operator--(int) {
				return reverse_iterator(_current++);
			}
			reference operator[](difference_type n) {
				return _current[n];
			}
			reverse_iterator& operator+=(difference_type n) {
				_current -= n;
				return *this;
			}
			reverse_iterator& operator-=(difference_type n) {
				_current += n;
				return *this;
			}
			reverse_iterator operator+(difference_type n) {
				return reverse_iterator(_current - n);
			}
			reverse_iterator operator-(difference_type n) {
				return reverse_iterator(_current + n);
			}
			reference operator[](difference_type n) const {
				return _current[n];
			}
	};

	template< class IteratorL, class IteratorR >
	bool operator==(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
		return lhs.base() == rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator!=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
		return lhs.base() != rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator<(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
		return lhs.base() > rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator>(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
		return lhs.base() < rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator<=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
		return lhs.base() >= rhs.base();
	}
	template< class IteratorL, class IteratorR >
	bool operator>=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
		return lhs.base() <= rhs.base();
	}
	template< class IteratorL, class IteratorR >
	reverse_iterator<IteratorL> operator+(typename reverse_iterator<IteratorL>::difference_type n, const reverse_iterator<IteratorR>& rhs) {
		return reverse_iterator<IteratorL>(rhs.base() - n);
	}
	template< class IteratorL, class IteratorR >
	reverse_iterator<IteratorL> operator-(typename reverse_iterator<IteratorL>::difference_type n, const reverse_iterator<IteratorR>& rhs) {
		return reverse_iterator<IteratorL>(rhs.base() + n);
	}
	template< class IteratorL, class IteratorR >
	reverse_iterator<IteratorL> operator+(const reverse_iterator<IteratorL>& lhs, typename reverse_iterator<IteratorL>::difference_type n) {
		return reverse_iterator<IteratorL>(lhs.base() - n);
	}
	template< class IteratorL, class IteratorR >
	reverse_iterator<IteratorL> operator-(const reverse_iterator<IteratorL>& lhs, typename reverse_iterator<IteratorL>::difference_type n) {
		return reverse_iterator<IteratorL>(lhs.base() + n);
	}
	template< class IteratorL, class IteratorR >
	typename reverse_iterator<IteratorL>::difference_type operator-(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
		return rhs.base() - lhs.base();
	}

}

#endif