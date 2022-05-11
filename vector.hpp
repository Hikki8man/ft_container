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
			
			void _rebuild_array(value_type *newData, const size_type & toDealloc) {
				for (size_type i = 0; i < _size; ++i) { // copy the data
					_alloc.construct(&newData[i], _data[i]);
					_alloc.destroy(&_data[i]);
				}
				if (toDealloc)
					_alloc.deallocate(_data, toDealloc);
				_data = newData;
			}

			void _build_array(const vector<T> &other, const size_type & n ) {
				for (size_t i = 0; i < n; ++i) {
					_alloc.construct(&_data[i], other._data[i]);
				}
			}
			template< class InputIt >
			void _build_array(InputIt first, InputIt last) {
				size_type n = last - first;
				for (size_type i = 0; i < n; ++i) {
					_alloc.construct(&_data[i], *(first + i));
				}
			}
			
			void _adjust_capacity(size_type newSize) {//if new size > *2 capacity, take exact size | maybe destroy old data
				if (newSize > _capacity) {
					value_type *newData;
			
					if (_capacity)
						newSize = _capacity * 2;
					newData = _alloc.allocate(newSize);
					_rebuild_array(newData, _capacity);
					_capacity = newSize;
				}
			}

			void _destroy_array() {
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(&_data[i]);
			}

		public:
			vector() : _data(NULL), _size(0), _capacity(0) {};

			vector(size_type size, const value_type & value) {//test with size max
				_size = size;
				_capacity = size;
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < size; i++)
					_alloc.construct(&_data[i], value);
			};
			vector(const vector<T>& src) {
				*this = src;
			};

			~vector() {
				if (!empty()) {
					_destroy_array();
				}
				if (_capacity)
					_alloc.deallocate(_data, _capacity);
			};

			vector<T>& operator=(const vector<T>& rhs) {
				if (this != &rhs) {
					if (!empty())
						_destroy_array();
					if (_capacity)
						_alloc.deallocate(_data, _capacity);
					
					_size = rhs._size;
					_alloc = rhs._alloc;
					_capacity = rhs._capacity;
					_data = _alloc.allocate(_capacity);
					_build_array(rhs, _size);
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
				if (n < _size) {//destroy old data
					for (size_type i = n; i < _size; ++i)
						_alloc.destroy(&_data[i]);
					_size = n;
				}
				if (n > _capacity) {
					_adjust_capacity(n);
				}
				while (_size < n) {
						std::cerr << "wowowo" << std::endl;
					try {
						_alloc.construct(_data + _size, val);
					} catch (...) {
						exit(1);
					}
					++_size;
				}
			}

			size_type	capacity() const {
				return _capacity;
			}

			bool empty() const {
				return _size ? false : true;
			}

			void reserve (size_type n) {//nul
				if (n > _capacity) {
					value_type *newData;
					newData = _alloc.allocate(n);
					_capacity = n;
					_rebuild_array(newData, _size);
				}
			}

			/* --- Element access --- */

			value_type & operator[](const size_t & i) const {
				return _data[i];
			}

			reference at(size_type n) {
				if (n >= _size)
					throw std::out_of_range("ft::vector::at");
				return _data[n];
			}

			const_reference at(size_type n) const {
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


			void clear() {
				if (!empty()) {
					_destroy_array();
					_size = 0;
				}
			}

			template<class InputIterator>
				void assign(InputIterator first, InputIterator last) {//maybe destroy old data
					size_type n = last - first;
					if (n > _capacity)
						_adjust_capacity(n);
					_size = n;
					_build_array(first, last);
				}

			void assign(size_type n, const value_type & val) {
				if (n > _capacity) {
					_adjust_capacity(n);
				}
				_size = n;
				//huu
			}

			void push_back(const value_type& val) {
				_adjust_capacity(_size + 1);
				_alloc.construct(&_data[_size], val);
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