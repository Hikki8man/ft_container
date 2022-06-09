#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory>
#include "iterator_traits.hpp"

namespace ft {

	template<class Pair>
	struct tree_node {
		typedef tree_node<Pair>* node_ptr;

		tree_node() : pair(), left(NULL), right(NULL), parent(NULL) {}

		tree_node(const Pair& pair) : pair(pair), left(NULL), right(NULL), parent(NULL) {}
	
		Pair pair;
		node_ptr left;
		node_ptr right;
		node_ptr parent;

	};

template< class Node >
	class bi_tree_iterator {

			public:

				typedef typename ft::iterator_traits<Node>::value_type value_type;
				typedef typename ft::iterator_traits<Node>::reference reference;
				typedef typename ft::iterator_traits<Node>::pointer pointer;
				typedef typename ft::iterator_traits<Node>::difference_type difference_type;
				typedef ft::bidirectional_iterator_tag	iterator_category;

				typedef bi_tree_iterator<Node> _Self;

				pointer _node;

				bi_tree_iterator() : _node() {}

				bi_tree_iterator(pointer _x) : _node(_x) {}


				pointer base() const { return _node; }

				reference operator*() const { return *_node; }

				pointer operator->() const { return _node; }

				_Self& operator++() {
					if (_node->right != NULL) {
						_node = _node->right;
						while (_node->left != NULL) {
							_node = _node->left;
						}
					}
					else {
						pointer _y = _node->parent;
						while (_y != NULL && _node == _y->right) {
							_node = _y;
							_y = _y->parent;
						}
						_node = _y;
					}
					return *this;
				}

				_Self operator++(int) {
					_Self _Tmp = *this;
					++*this;
					return _Tmp;
				}

				_Self& operator--() {
					if (_node->left != NULL) {
						_node = _node->left;
						while (_node->right != NULL) {
							_node = _node->right;
						}
					}
					else {
						pointer _y = _node->parent;
						while (_y != NULL && _node == _y->left) {
							_node = _y;
							_y = _y->parent;
						}
						_node = _y;
					}
					return *this;
				}

				_Self operator--(int) {
					_Self _Tmp = *this;
					--*this;
					return _Tmp;
				}
	};

	template<class Node>
		bool operator==(const bi_tree_iterator<Node>& _Left, const bi_tree_iterator<Node>& _Right) {
			return _Left.base() == _Right.base();
		}
	
	template<class Node>
		bool operator!=(const bi_tree_iterator<Node>& _Left, const bi_tree_iterator<Node>& _Right) {
			return _Left.base() != _Right.base();
		}

	template<class Pair, class _Alloc = std::allocator<ft::tree_node<Pair> > >
	class BItree {

		public:

			typedef Pair value_type;
			typedef _Alloc allocator_type;

			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;

			typedef ft::bi_tree_iterator<pointer> iterator;

			pointer _root;
			_Alloc _alloc;

			pointer _min(pointer _x) {
				while (_x->left != NULL) {
					_x = _x->left;
				}
				return _x;
			}

			pointer _max(pointer _x) {
				while (_x->right != NULL) {
					_x = _x->right;
				}
				return _x;
			}

			BItree() : _root(NULL) {}

			void insert(const value_type& val) {
				if (_root == NULL) {
					// _root = new tree_node<value_type>(val);
					_root = _alloc.allocate(1);
					_alloc.construct(_root, val);
				}
				else {
					pointer curr = _root;
					while (curr != NULL) {
						if (val < curr->pair) {
							if (curr->left == NULL) {
								curr->left = new tree_node<value_type>(val);
								curr->left->parent = curr;
								break;
							}
							else {
								curr = curr->left;
							}
						}
						else {
							if (curr->right == NULL) {
								curr->right = new tree_node<value_type>(val);
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

			void erase (iterator pos) {
				pointer curr = pos.base();
				if (curr->left == NULL && curr->right == NULL) {
					if (curr->parent->left == curr) {
						curr->parent->left = NULL;
					}
					else {
						curr->parent->right = NULL;
					}
					delete curr;
				}
				else if (curr->left != NULL && curr->right == NULL) {
					if (curr->parent->left == curr) {
						curr->parent->left = curr->left;
						curr->left->parent = curr->parent;
					}
					else {
						curr->parent->right = curr->left;
						curr->left->parent = curr->parent;
					}
					delete curr;
				}
				else if (curr->left == NULL && curr->right != NULL) {
					if (curr->parent->left == curr) {
						curr->parent->left = curr->right;
						curr->right->parent = curr->parent;
					}
					else {
						curr->parent->right = curr->right;
						curr->right->parent = curr->parent;
					}
					delete curr;
				}
				else {
					pointer min = _min(curr->right);
					curr->pair = min->pair;
					erase(min);
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