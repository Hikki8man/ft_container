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
	
		tree_node &operator=(const tree_node &other) {
			pair = other.pair;
			left = other.left;
			right = other.right;
			parent = other.parent;
			return *this;
		}

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

	template<typename Key, class Pair, class Compare, class _Alloc = std::allocator<ft::tree_node<Pair> > >
	class BItree {

		public:

			typedef Key key_type;
			typedef Pair value_type;
			typedef _Alloc allocator_type;

			// node type
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef ft::tree_node<value_type> node_type;

			typedef ft::bi_tree_iterator<pointer> iterator;


			pointer _root;
			_Alloc _alloc;
			Compare _comp;

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
					_root = _new_node(val);
				}
				else {
					pointer curr = _root;
					while (curr != NULL) {
						if (_comp(val.first, curr->pair.first)) {
							if (curr->left == NULL) {
								curr->left = _new_node(val);
								curr->left->parent = curr;
								break;
							}
							else {
								curr = curr->left;
							}
						}
						else {
							if (curr->right == NULL) {
								curr->right =_new_node(val);
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

			void erase(iterator pos) {
				
			}

			iterator find(const key_type& k) {//do const one
				pointer node = _root;

				while (node != NULL) {
					if (k == node->pair.first) {
						return iterator(node);
					}
					else if (_comp(k, node->pair.first)) {
						node = node->left;
					}
					else {
						node = node->right;
					}
				}
				return iterator(end());
			}

			iterator lower_bound(const key_type& k) {
				
			}

			iterator begin() {
				return iterator(_min(_root));
			}

			iterator end() {
				return iterator(NULL);
			}

			private:
			
				pointer _new_node(const value_type& val) {
					pointer _x = _alloc.allocate(1);
					_alloc.construct(_x, val);
					return _x;
				}

	};


	
}

#endif