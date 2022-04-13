#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <cstring>

template < class T, class Alloc = std::allocator<T> >
class vector {
	typedef T value_type;
	typedef size_t size_type;
	public:
		vector() : _data(NULL), _size(0), _capacity(0) {};

		vector(size_type size, const value_type & value) {
			_size = size;
			_capacity = size;
			try {
				_data = _alloc.allocate(_capacity);
			}
			catch (std::exception & e) {
				std::cout << e.what() << std::endl;
			}
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

		size_type size() const {
			return _size;
		}
		size_type	capacity() const {
			return _capacity;
		}

		void reserve (size_type n) { //throw exception if neg
			if (n > _capacity) {
				value_type *newData;
				try {
					newData = _alloc.allocate(n);//max size et tt
					_capacity = n;
				}
				catch (std::exception & e) {
					std::cout << e.what() << std::endl;
					return ;
				}
				_copy_array(newData, _size);
			}
		}

		//if empty ?
		void resize (size_type n, value_type val = value_type()) {
			// reserve(n);
			(void)val;
			if (n < _size) {
				_size = n;
			}

		}

		bool empty() const {
			return _size ? false : true;
		}

		void	push_back(const value_type& val) {
			size_type toDealloc = _capacity;
			if (_size + 1 > _capacity) {
				_adjust_capacity(_size + 1);
				value_type *newData;
				try {
					newData = _alloc.allocate(_capacity);
				}
				catch (std::exception & e) {
					std::cout << e.what() << std::endl;
					return ;
				}
				_copy_array(newData, toDealloc);
			}
			_data[_size] = val;
			++_size;
		}

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
			{
				try {
					_alloc.deallocate(_data, toDealloc);
				}
				catch (std::exception & e) {
					std::cout << e.what() << std::endl;
				}
			}
			_data = newData;
		}
		
		void _adjust_capacity(const size_t & newSize) {
			if (_capacity == 0)
				_capacity = newSize;
			else if (newSize > _capacity)
				_capacity *= 2;
		}
};

#endif