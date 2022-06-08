#ifndef BI_TREE_ITERATOR_HPP
#define BI_TREE_ITERATOR_HPP

#include "binary_tree.hpp"
#include "iterator_traits.hpp"

namespace ft {

	template< typename _Iterator >
	struct bi_tree_iterator {

			_Iterator _node;

			typedef _Iterator value_type;
			typedef _Iterator& reference;
			typedef _Iterator* pointer;

			typedef ft::bidirectional_iterator_tag	iterator_category;
			typedef ptrdiff_t	difference_type;

			typedef bi_tree_iterator<_Iterator> _Self;
			typedef ft::tree_node<value_type>::node_ptr _Base_ptr;
			typedef bi_tree_iterator<_Iterator>* _Link_type;

			bi_tree_iterator() : _node() {}

			bi_tree_iterator(_Base_ptr _x) : _node(_x) {}

			reference operator*() const { return *_node; }

			pointer operator->() const { return _node; }

			_Self& operator++() {
				_node++;
				return *this;
			}

	};
}

#endif