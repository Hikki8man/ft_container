#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory>
#include "iterator_traits.hpp"
#include "pair.hpp"

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
				typedef tree_node<value_type>* _Link_type;

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

	template<typename _Key, class _Pair, class _Compare, class _Alloc = std::allocator<ft::tree_node<_Pair> > >
	class BItree {

		public:

			typedef _Key key_type;
			typedef _Pair value_type;
			// typedef value_type* 		pointer;
			// typedef const value_type* 	const_pointer;
			// typedef value_type& 		reference;
			// typedef const value_type& 	const_reference;
			typedef std::size_t 				size_type;
			typedef std::ptrdiff_t 			difference_type;
			typedef _Alloc 				allocator_type;

			// node type
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef ft::tree_node<value_type> node_type;//??

			typedef ft::bi_tree_iterator<pointer> iterator;
			typedef ft::bi_tree_iterator<const_pointer> const_iterator;

		
			pointer _root;
			_Alloc _alloc;
			_Compare _comp;

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

			BItree() : _root(NULL), _size(0) {}

			void insert(const value_type& val) {
				if (_root == NULL) {
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
				++_size;
			}

			void erase(iterator pos) {
				pointer curr = pos.base();//check if it is a valid iterator

				// if no child
				if (curr->left == NULL && curr->right == NULL) {
					if (curr->parrent == NULL) {
						_delete_node(curr);//does root is null?
					}
					else {
						if (curr->parent->left == curr) {
							curr->parent->left = NULL;
						}
						else {
							curr->parent->right = NULL;
						}
						_delete_node(curr);
					}
				} // if one child
				else if (curr->left == NULL || curr->right == NULL) {
					if (curr->left == NULL) {
						if (curr->parent == NULL) {
							_root = curr->right;
							_root->parent = NULL;
							_delete_node(curr);
						}
						else {
							if (curr->parent->left == curr) {
								curr->parent->left = curr->right;
								curr->right->parent = curr->parent;
								_delete_node(curr);
							}
							else {
								curr->parent->right = curr->right;
								curr->right->parent = curr->parent;
								_delete_node(curr);
							}
						}
					}
					else {
						if (curr->parent == NULL) {
							_root = curr->left;
							_root->parent = NULL;
							_delete_node(curr);
						}
						else {
							if (curr->parent->left == curr) {
								curr->parent->left = curr->left;
								curr->left->parent = curr->parent;
								_delete_node(curr);
							}
							else {
								curr->parent->right = curr->left;
								curr->left->parent = curr->parent;
								_delete_node(curr);
							}
						}
					}
				}
				else {
					pointer succ = _min(curr->right);
					
				}
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
				return end();
			}

			const_iterator find(const key_type& k) const {
				pointer node = _root;

				while (node != NULL) {
					if (k == node->pair.first) {
						return const_iterator(node);
					}
					else if (_comp(k, node->pair.first)) {
						node = node->left;
					}
					else {
						node = node->right;
					}
				}
				return end();
			}

			size_t count(const key_type& k) {
				if (find(k) != end()) {
					return 1;
				}
				return 0;
			}

			iterator begin() {
				return iterator(_min(_root));
			}

			const_iterator begin() const {
				return const_iterator(_min(_root));
			}

			iterator end() {
				return iterator(NULL);
			}

			const_iterator end() const {
				return const_iterator(NULL);
			}

			iterator lower_bound(const key_type& k) {
				pointer node = _root;
				if (_comp(_max(_root)->pair.first, k)) {
					return end(); // stl doesnt segfault when you try to dereference an iterator that is end() if key is an int
				}
				while (node != NULL) {
					if (k == node->pair.first) {
						return iterator(node);
					}
					else if (node->parent != NULL && !_comp(k, node->parent->pair.first) && _comp(k, node->pair.first)) {
						return iterator(node);
					}
					else if (_comp(k, node->pair.first)) {
						node = node->left;
					}
					else {
						node = node->right;
					}
				}
				return iterator(_root);
			}

			const_iterator lower_bound(const key_type& k) const {
				pointer node = _root;
				if (_comp(_max(_root)->pair.first, k)) {
					return end(); // stl doesnt segfault when you try to dereference an iterator that is end() if key is an int
				}
				while (node != NULL) {
					if (k == node->pair.first) {
						return const_iterator(node);
					}
					else if (node->parent != NULL && !_comp(k, node->parent->pair.first) && _comp(k, node->pair.first)) {
						return const_iterator(node);
					}
					else if (_comp(k, node->pair.first)) {
						node = node->left;
					}
					else {
						node = node->right;
					}
				}
				return const_iterator(_root);
			}

			iterator upper_bound(const key_type& k) {
				pointer node = _root;
				if (_comp(_max(_root)->pair.first, k) || _max(_root)->pair.first == k) { // pas opti du tout
					return end(); // stl doesnt segfault when you try to dereference an iterator that is end() if key is an int
				}
				while (node != NULL) {
					if (k == node->pair.first && node->right != NULL) {
						return iterator(node->right);
					}
					else if (node->parent != NULL && !_comp(k, node->parent->pair.first) && _comp(k, node->pair.first)) {
						return iterator(node);
					}
					else if (_comp(k, node->pair.first)) {
						node = node->left;
					}
					else {
						node = node->right;
					}
				}
				return iterator(_root);
			}

			const_iterator upper_bound(const key_type& k) const {
				pointer node = _root;
				if (_comp(_max(_root)->pair.first, k) || _max(_root)->pair.first == k) { // pas opti du tout
					return end(); // stl doesnt segfault when you try to dereference an iterator that is end() if key is an int
				}
				while (node != NULL) {
					if (k == node->pair.first && node->right != NULL) {
						return const_iterator(node->right);
					}
					else if (node->parent != NULL && !_comp(k, node->parent->pair.first) && _comp(k, node->pair.first)) {
						return const_iterator(node);
					}
					else if (_comp(k, node->pair.first)) {
						node = node->left;
					}
					else {
						node = node->right;
					}
				}
				return const_iterator(_root);
			}

			// Capacity
			
			size_type size() {
				return _size;
			}

			bool empty() {
				return _size == 0;
			}

			size_type max_size() {
				return _alloc.max_size();
			}

			// Element access



			private:
			
				pointer _new_node(const value_type& val) {
					pointer _x = _alloc.allocate(1);
					_alloc.construct(_x, val);
					return _x;
				}

				void _delete_node(pointer x) {
					_alloc.destroy(x);
					_alloc.deallocate(x, 1);
					x = NULL;
					--_size;
				}

				size_type _size;

	};
}

#endif