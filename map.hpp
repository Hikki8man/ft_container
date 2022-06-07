#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include "pair.hpp"

namespace ft {

	template< class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
		public:

			typedef Key                           key_type;
			typedef T                             mapped_type;
			typedef ft::pair<const Key, T>        value_type;
			typedef std::size_t                   size_type;
			typedef std::ptrdiff_t                difference_type;
			typedef Compare                       key_compare;
			typedef Alloc                         allocator_type;
			typedef value_type&                   reference;
			typedef const value_type&             const_reference;
			typedef typename Alloc::pointer       pointer;
			typedef typename Alloc::const_pointer const_pointer;
			// typedef map_iterator<pointer>                    iterator;
			// typedef map_iterator<const_pointer>                iterator;
			// typedef ft::reverse_iterator<iterator>            reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
	};
}

#endif