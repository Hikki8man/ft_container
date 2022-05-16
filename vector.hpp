#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <cstring>
#include "reverve_iterator.hpp"
#include "random_access_iterator.hpp"

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
			typedef ft::random_access_iterator<pointer> iterator;
			typedef ft::random_access_iterator<const_pointer> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;


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

			size_type _adjust_capacity(size_type newCap) {
				if (newCap > _capacity * 2)
					return newCap;
				else
					return _capacity * 2;
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
				clear();
				if (_capacity)
					_alloc.deallocate(_data, _capacity);
			};

			vector<T>& operator=(const vector<T>& rhs) {
				if (this != &rhs) {
					clear();
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
				if (n > _capacity) {
					reserve(_adjust_capacity(n));
				}
				if (n < _size) {
					for (size_type i = n; i < _size; ++i)
						_alloc.destroy(&_data[i]);
					_size = n;
				}//what if n == _size | test with data null
				else if (n > _size) {
					for (size_type i = _size; i < n; ++i) {
						_alloc.construct(&_data[i], val);
					}
					_size = n;
				}
			}

			size_type	capacity() const {
				return _capacity;
			}

			bool empty() const {
				return _size ? false : true;
			}

			void reserve(size_type n) {
				if (n > max_size())
					throw(std::length_error("vector::reserve: max_size exceeded"));
				if (n > _capacity) {
					pointer newData = _alloc.allocate(n);
					for (size_type i = 0; i < _size; ++i) {
						_alloc.construct(newData + i, _data[i]);
						_alloc.destroy(_data + i);
					}
					if (_capacity)
						_alloc.deallocate(_data, _capacity);
					_data = newData;
					_capacity = n;
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

			void assign(size_type n, const value_type & val) {
				clear();
				_size = n;
				if (n > _capacity)
					reserve(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_data[i], val);
			}

			template<class InputIterator>
				void assign(InputIterator first, InputIterator last) {
					clear();
					_size = last - first;
					// std::cout << _size << std::endl;
					if (_size > _capacity)
						reserve(_size);
					for (size_type i = 0; i < _size; i++) {
						value_type val = *first;
						_alloc.construct(&_data[i], val);
						++first;
					}

				}


			void push_back(const value_type& val) {
				if (_size == _capacity)
					reserve(_adjust_capacity(_size + 1));
				_alloc.construct(_data + _size, val);
				++_size;
			}

			void pop_back() {
				if (empty())
					return;
				--_size;
				_alloc.destroy(&_data[_size]);
			}


			iterator insert(iterator pos, const value_type& val) {
				// val could be an existing element of this vector, so make a
	    		// copy of it before _M_insert_aux moves elements around.
				difference_type i = pos - begin();
				insert(pos, val);
				return iterator(_data + i);
			}		

			void insert(iterator pos, size_type count, const value_type& val) {
				difference_type i = pos - begin();

				if (_size + count > _capacity)
					reserve(_adjust_capacity(_size + count));//pas opti du tout
		
				size_type newSize = _size + count;
				iterator ite = end() - 1;

				for (iterator it = iterator(begin() + newSize - 1); it != iterator(begin() + i + count - 1); --it) {
					_alloc.construct(it.base(), *ite);
					_alloc.destroy(ite.base());
					--ite;
				}

				iterator endo(_data + i + count);
	
				for (ite = begin() + i; ite != endo; ++ite) {
					_alloc.construct(ite.base(), val);
				}
				_size += count;
			}

			template<class InputIterator>
				void insert(iterator pos, InputIterator first, InputIterator last) {
					std::cout << "HELLO" << std::endl;
					difference_type i = pos - begin();
					size_type count = last - first;
					if (_size + count > _capacity)
						reserve(_adjust_capacity(_size + count));//pas opti du tout
		
					size_type newSize = _size + count;
					iterator ite = end() - 1;

					for (iterator it = iterator(begin() + newSize - 1); it != iterator(begin() + i + count - 1); --it) {
						_alloc.construct(it.base(), *ite);
						_alloc.destroy(ite.base());
						--ite;
					}

					iterator endo(_data + i + count);
	
					// for (ite = begin() + i; ite != endo; ++ite) {
					// 	_alloc.construct(ite.base(), *first++);
					// }
					_size += count;
				}
				

			/* --- Iterator --- */
			iterator begin() {
				return iterator(_data);
			}
			const_iterator begin() const {
				return const_iterator(_data);
			}
			iterator end() {
				return iterator(_data + _size);
			}
			const_iterator end() const {
				return const_iterator(_data + _size);
			}
			reverse_iterator rbegin() {
				return reverse_iterator(end());
			}
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(end());
			}
			reverse_iterator rend() {
				return reverse_iterator(begin());
			}
			const_reverse_iterator rend() const {
				return const_reverse_iterator(begin());
			}

	};
}

#endif