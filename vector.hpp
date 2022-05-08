#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <cstring>
#include "vector_iterator.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

		public:
			typedef T value_type;
			typedef std::size_t size_type;
			typedef Alloc allocator_type;
			typedef std::ptrdiff_t difference_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef vector_iterator<pointer> iterator;
			typedef vector_iterator<const_pointer> const_iterator;


		protected:
			pointer _data;
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
			
			void _adjust_capacity(size_t newSize) {//if new size > *2 capacity, take exact size | maybe destroy old data
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

			vector<T>& operator=(const vector<T>& rhs) {
				if (this != &rhs) {
					_size = rhs._size;
					_capacity = rhs._capacity;
					_data = _alloc.allocate(_capacity);
					_copy_array(_data, _capacity);
				}
			};

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

			// void shrink_to_fit() { haa not in c++98
			// 	value_type *newData;

			// 	newData = _alloc.allocate(_size);
			// 	_copy_array(newData, _capacity);
			// 	_capacity = _size;
			// }

			/* --- Element access --- */

			value_type & operator[](const size_t & i) const {
				return _data[i];
			}

			reference at (size_type n) {
				if (n >= _size)
					throw std::out_of_range("ft::vector::at");
				return _data[n];
			}

			const_reference at (size_type n) const {
				if (n >= _size)
					throw std::out_of_range("ft::vector::at");
				return _data[n];
			}

			reference front() {
				return _data[0];
			}

			const_reference front() const {
				return _data[0];
			}

			reference back() {
				return _data[_size - 1];
			}

			const_reference back() const {
				return _data[_size - 1];
			}

			/* --- Modifiers --- */

			template<class InputIterator>
				void assign(InputIterator first, InputIterator last) {//maybe destroy old data
					size_type n = last - first;
					if (n > _capacity)
						_adjust_capacity(n);
					_size = n;
					for (size_type i = 0; i < n; ++i) {
						_data[i] = *first;
						++first;
					}
				}

			void assign(size_type n, const value_type & val) {
				if (n > _capacity) {
					_adjust_capacity(n);
				}
				_size = n;
				for (size_type i = 0; i < n; i++)//maybe destroy old data
					_data[i] = val;
			}

			void push_back(const value_type& val) {
				_adjust_capacity(_size + 1);
				_data[_size] = val;
				++_size;
			}

			void pop_back() {
				if (empty())
					return;
				--_size;
				_alloc.destroy(&_data[_size]);
			}

			/* --- Iterator --- */
			iterator begin() {
				return iterator(_data);
			}
			iterator end() {
				return iterator(_data + _size);
			}
	};
}

#endif