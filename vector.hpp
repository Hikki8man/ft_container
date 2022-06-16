#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <cstring>
#include "reverve_iterator.hpp"
#include "random_access_iterator.hpp"
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "lexicographical_compare.hpp"

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

			size_type _adjust_capacity(size_type newCap) {
				if (newCap > _capacity * 2)
					return newCap;
				else
					return _capacity * 2;
			}

			void _destroy_array() {
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(_data + i);
			}

		public:
			explicit vector() : _data(NULL), _size(0), _capacity(0) {};

			explicit vector(size_type size, const value_type & value = value_type()) {//test with size max
				_size = size;
				_capacity = size;
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < size; i++)
					_alloc.construct(&_data[i], value);
			};
			vector(const vector<T>& src) : _data(NULL), _size(0), _capacity(0) {
				if (src._capacity) {
					_capacity = src._size;
					_data = _alloc.allocate(_capacity);
					for (size_type i = 0; i < src._size; ++i) {
						_alloc.construct(&_data[i], src._data[i]);
						++_size;
					}
				}
			};

			~vector() {
				clear();
				if (_capacity)
					_alloc.deallocate(_data, _capacity);
			};

			template<class InputIterator>
				vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL) {
					_size = last - first;
					_capacity = _size;
					_data = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&_data[i], *(first + i));
				}

			vector<T>& operator=(const vector<T>& rhs) {
				if (this != &rhs) {
					clear();
					if (_capacity)
						_alloc.deallocate(_data, _capacity);
					
					_size = rhs._size;
					_alloc = rhs._alloc;
					_capacity = rhs._capacity;
					if (_capacity) {
						_data = _alloc.allocate(_capacity);
						for (size_type i = 0; i < _size; i++) {
							_alloc.construct(&_data[i], rhs._data[i]);
						}
					}
				}
				return *this;
			};

			/* --- Capacity --- */

			size_type 	size() const {
				return _size;
			}

			size_type	max_size() const {
				return _alloc.max_size();
			}

			void resize (size_type n, value_type val = value_type()) {//redo
				if (n > _capacity) {
					reserve(_adjust_capacity(n));//pas bon sur windows
					// reserve(n);
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
						// _alloc.destroy(_data + i);
					}
					_destroy_array();
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
				if (n > _capacity)
					reserve(n);
				_size = n;
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_data[i], val);
			}

			template<class InputIterator>
				void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL) {
					clear();
					difference_type n = last - first;
					if (n > _capacity)
						reserve(n);
					for (difference_type i = 0; i < n; ++i) {
						_alloc.construct(_data + i, *first);
						++first;
						++_size;
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
				if (pos == end() && _size + 1 <= _capacity) {
					_alloc.construct(_data + _size, val);
					++_size;
					return end() - 1;
				}
				else if (_size + 1 > _capacity) {
					pointer newData = _alloc.allocate(_adjust_capacity(_size + 1));
					difference_type offset = pos - begin();

					_alloc.construct(newData + offset, val);
					for (size_type i = 0; i <= _size; ++i) {
						if (i < offset)
							_alloc.construct(newData + i, _data[i]);
						else if (i > offset)
							_alloc.construct(newData + i, _data[i - 1]);
					}
					_destroy_array();
					_alloc.deallocate(_data, _capacity);
					_capacity = _adjust_capacity(_size + 1);
					_data = newData;
					++_size;
					return begin() + offset;
				}
				else {
					difference_type offset = pos - begin();
					_alloc.construct(_data + _size, *(_data + _size - 1));
					for (size_type i = _size - 1; i > offset; --i) {
						_data[i] = _data[i - 1];
					}
					*pos = val;
					++_size;

					return begin() + offset;
				}
			}
			void insert(iterator pos, size_type count, const value_type& val) {
				if (_size + count > _capacity) {
					difference_type posIndex = pos - begin();
					pointer newData = _alloc.allocate(_adjust_capacity(_size + count));
					size_type newCapacity = _adjust_capacity(_size + count);
					for (size_type i = 0; i < count; ++i) {
						_alloc.construct(newData + posIndex + i, val);
					}
					size_t j = 0;
					for (size_type i = 0; i < _size + count; ++i) {
						if (i >= posIndex && i < posIndex + count)
							continue;
						_alloc.construct(newData + i, _data[j]);
						++j;
					}
					_destroy_array();
					_alloc.deallocate(_data, _capacity);
					_capacity = newCapacity;
					_data = newData;
					_size += count;
					return;
				}

				for (iterator it = end() + count -1; it != pos + count -1; --it) {
						if (it >= end())
							_alloc.construct(it.base(), *(it - count));
						else
							*it = *(it - count);
				}
				for (iterator it = pos; it != pos + count; ++it) {
					if (it >= end())
						_alloc.construct(it.base(), val);
					else
						*it = val;
				}
				_size += count;
			}

			template<class InputIterator>
				void insert(iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL) {
					difference_type count = last - first;
					if (_size + count > _capacity) {
						difference_type posIndex = pos - begin();
						pointer newData = _alloc.allocate(_adjust_capacity(_size + count));
						size_type newCapacity = _adjust_capacity(_size + count);
						for (size_type i = 0; i < count; ++i) {
							_alloc.construct(newData + posIndex + i, *first);
							++first;
						}
						size_t j = 0;
						for (size_type i = 0; i < _size + count; ++i) {
							if (i >= posIndex && i < posIndex + count)
								continue;
							_alloc.construct(newData + i, _data[j]);
							++j;
						}
						_destroy_array();
						_alloc.deallocate(_data, _capacity);
						_capacity = newCapacity;
						_data = newData;
						_size += count;
						return;
					}
					for (iterator it = end() + count -1; it != pos + count -1; --it) {
						if (it >= end())
							_alloc.construct(it.base(), *(it - count));
						else
							*it = *(it - count);
					}
					for (iterator it = pos; first != last; ++it) {
						if (it >= end())
							_alloc.construct(it.base(), *first);
						else
							*it = *first;
						++first;
					}
					_size += count;
				}

			void swap(vector& b) {
				std::swap(_data, b._data);
				std::swap(_size, b._size);
				std::swap(_capacity, b._capacity);
				std::swap(_alloc, b._alloc);
			}
				
			iterator erase(iterator pos) {
				if (pos == end())
					return end();
				for (iterator it = pos; it != end() - 1; ++it) {
					*it = *(it + 1);
				}
				_alloc.destroy((end() - 1).base());
				--_size;
				return pos;
			}

			iterator erase(iterator first, iterator last) {
				iterator firstp = first;
				for (iterator it = last; it != end(); ++it) {
					*firstp = *it;
					++firstp;
				}
				for (reverse_iterator it = rbegin(); it != reverse_iterator(firstp); ++it) {
					_alloc.destroy(it.base().base() - 1);
					--_size;
				}
				return first;
			}

			/* --- Alloctor --- */
			allocator_type get_allocator() const {
				return _alloc;
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

	template<class T, class Alloc>
		void swap(vector<T, Alloc>& a, vector<T, Alloc>& b) {
			a.swap(b);
		}

	/* --- Operators --- */

	template<class T, class Alloc>
		bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

	template<class T, class Alloc>
		bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
			return !(lhs == rhs);
		}
	
	template<class T, class Alloc>
		bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
	
	template<class T, class Alloc>
		bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
			return rhs < lhs;
		}
	
	template<class T, class Alloc>
		bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
			return !(lhs > rhs);
		}
	
	template<class T, class Alloc>
		bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
			return !(lhs < rhs);
		}
}

#endif