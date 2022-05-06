#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <cstring>
#include "vector_iterator.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {
		typedef T value_type;
		typedef size_t size_type;

		typedef typename ft::iterator_traits<T>::value_type value_type;
		typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<T>::difference_type difference_type;
		typedef typename ft::iterator_traits<T>::pointer pointer;
		typedef typename ft::iterator_traits<T>::reference reference;

		private:
			value_type *_data;
			size_type _size;
			size_type _capacity;
			Alloc _alloc;
			
			void _copy_array(value_type *newData, const size_type & toDealloc) {
				for (size_type i = 0; i < _size; ++i) {
					newData[i] = _data[i];
				}
				if (toDealloc)
					_alloc.deallocate(_data, toDealloc);
				_data = newData;
			}
			
			void _adjust_capacity(size_t newSize) {
				if (newSize > _capacity) {
					value_type *newData;
			
					if (_capacity)
						newSize = _capacity * 2;
					newData = _alloc.allocate(newSize);
					_copy_array(newData, _capacity);
					_capacity = newSize;
				}
			}

		public:
			vector() : _data(NULL), _size(0), _capacity(0) {};

			vector(size_type size, const value_type & value) {//test with size max
				_size = size;
				_capacity = size;
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < size; i++)
					_data[i] = value;
			};
			vector(const vector<T>& src);

			~vector() {
				if (_data)
					_alloc.deallocate(_data, _capacity);
			};

			vector<T>& operator=(const vector<T>& rhs);

			value_type & operator[](const size_t & i) const {
				return _data[i]; //no protection askip
			}

			/* --- Capacity --- */
			size_type 	size() const {
				return _size;
			}

			size_type	max_size() const {
				return _alloc.max_size();
			}

			void resize (size_type n, value_type val = value_type()) {
				if (n < _size) {
					_size = n;
				}
				else if (n > _size) {
					_adjust_capacity(n);
					while (_size < n) {
						_data[_size] = val;
						++_size;
					}
				}
			}

			size_type	capacity() const {
				return _capacity;
			}

			bool empty() const {
				return _size ? false : true;
			}

			void reserve (size_type n) {
				if (n > _capacity) {
					value_type *newData;
					newData = _alloc.allocate(n);
					_capacity = n;
					_copy_array(newData, _size);
				}
			}

			void shrink_to_fit() {
				value_type *newData;

				newData = _alloc.allocate(_size);
				_copy_array(newData, _capacity);
				_capacity = _size;
			}

			/* --- Modifiers --- */
			void	push_back(const value_type& val) {
				_adjust_capacity(_size + 1);
				_data[_size] = val;
				++_size;
			}

	};
}

#endif