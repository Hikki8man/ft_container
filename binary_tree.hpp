#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory>
// #include "bi_tree_iterator.hpp"
#include "iterator_traits.hpp"

namespace ft {

	template<class value_type>
	struct tree_node {
		typedef tree_node<value_type>* node_ptr;

		tree_node() : value(), left(NULL), right(NULL), parent(NULL) {}

		tree_node(const value_type& value) : value(value), left(NULL), right(NULL), parent(NULL) {}
	
		value_type value;
		node_ptr left;
		node_ptr right;
		node_ptr parent;

		value_type& operator*() { return value; }

		tree_node& operator++() {
			if (right) {
				*this = *right;
			} else {
				node_ptr p = parent;
				while (p && p->right == *this) {
					*this = *p;
					p = p->parent;
				}
				if (p) {
					*this = *p;
				}
			}
			return *this;
		}
	};

template< typename _Iterator >
	struct bi_tree_iterator {

			_Iterator _node;

			typedef _Iterator value_type;
			typedef _Iterator& reference;
			typedef _Iterator* pointer;

			typedef ft::bidirectional_iterator_tag	iterator_category;
			typedef ptrdiff_t	difference_type;

			typedef bi_tree_iterator<_Iterator> _Self;
			typedef typename ft::tree_node<value_type>::node_ptr _Base_ptr;
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

	template<typename _Key, typename _Val, typename _Alloc = std::allocator<_Val> >
	class BItree {

		// protected:
		public:
			typedef tree_node<_Val> node;
			node *_root;

			template< class _node_ptr >
			_node_ptr _min(_node_ptr _x) {
				while (_x->left != NULL) {
					_x = _x->left;
				}
				return _x;
			}

			template< class _node_ptr >
			_node_ptr _max(_node_ptr _x) {
				while (_x->right != NULL) {
					_x = _x->right;
				}
				return _x;
			}



		public:

			typedef _Key key_type;
			typedef _Val value_type;
			typedef _Alloc allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;

			typedef ft::bi_tree_iterator<node*> iterator;

			BItree() : _root(NULL) {}

			void insert(const value_type& val) {
				if (_root == NULL) {
					_root = new node(val);
				}
				else {
					node *curr = _root;
					while (curr != NULL) {
						if (val < curr->value) {
							if (curr->left == NULL) {
								curr->left = new node(val);
								curr->left->parent = curr;
								break;
							}
							else {
								curr = curr->left;
							}
						}
						else {
							if (curr->right == NULL) {
								curr->right = new node(val);
								curr->right->parent = curr;
								break;
							}
							else {
								curr = curr->right;
							}
						}
					}
				}
			}

			iterator begin() {
				return iterator(_min(_root));
			}

			iterator end() {
				return iterator(NULL);
			}

	};


	
}

#endif