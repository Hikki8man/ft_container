#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory>
#include "iterator_traits.hpp"
#include "pair.hpp"

namespace ft {

	template<class Pair>
		struct tree_node;

	template<class value_type>
	struct tree_node_base {

		typedef tree_node<value_type>* node_ptr;

		tree_node_base() : left(NULL), right(NULL), parent(NULL) {}

		tree_node_base(const tree_node_base & src) {
			left = src.left;
			right = src.right;
			parent = src.parent;
		}

		~tree_node_base() {}
	
		tree_node_base &operator=(const tree_node_base &other) {
			left = other.left;
			right = other.right;
			parent = other.parent;
			return *this;
		}


		node_ptr left;
		node_ptr right;
		node_ptr parent;

	};

	template<class Pair>
	struct tree_node : public ft::tree_node_base<Pair> {

		typedef ft::tree_node_base<Pair> base;
		typedef tree_node<Pair>* node_ptr;

		tree_node() : base(), pair() {}
		tree_node(const Pair &p) : base(), pair(p) {}
		tree_node(const tree_node & src) : base(src), pair(src.pair) {}
		~tree_node() {}
		tree_node &operator=(const tree_node &other) {
			base::operator=(other);
			pair = other.pair;
			return *this;
		}

		node_ptr next() {
			if (this->right != NULL) {
				node_ptr tmp = this->right;
				while (tmp->left != NULL) {
					tmp = tmp->left;
				}
				return tmp;
			}
			node_ptr tmp = this->parent;
			while (tmp != NULL && tmp->right == this) {
				tmp = tmp->parent;
			}
			return tmp;
		}

		node_ptr prev() {
			if (this->left != NULL) {
				node_ptr tmp = this->left;
				while (tmp->right != NULL) {
					tmp = tmp->right;
				}
				return tmp;
			}
			node_ptr tmp = this->parent;
			while (tmp != NULL && tmp->left == this) {
				tmp = tmp->parent;
			}
			return tmp;
		}

		node_ptr min() {
			node_ptr tmp = this;
			while (tmp->left != NULL) {
				tmp = tmp->left;
			}
			return tmp;
		}

		node_ptr max() {
			node_ptr tmp = this;
			while (tmp->right != NULL) {
				tmp = tmp->right;
			}
			return tmp;
		}

		Pair pair;
	};

template< class Node, class Node_Base >
	class bi_tree_iterator {

			public:

				typedef typename ft::iterator_traits<Node>::value_type value_type;
				typedef typename ft::iterator_traits<Node>::reference reference;
				typedef typename ft::iterator_traits<Node>::pointer pointer;
				typedef typename ft::iterator_traits<Node>::difference_type difference_type;
				typedef ft::bidirectional_iterator_tag	iterator_category;

				typedef bi_tree_iterator<Node, Node_Base> _Self;
				typedef tree_node<value_type>* _Link_type;

				// typedef Node_Base<value_type>* _Base_ptr;

				pointer _node;
				Node_Base _sentinel;

				bi_tree_iterator() : _node(), _sentinel() {}

				bi_tree_iterator(pointer _x, Node_Base _s) : _node(_x), _sentinel(_s) {}

				bi_tree_iterator(const _Self &_x) : _node(_x._node), _sentinel(_x._sentinel) {}

				bi_tree_iterator& operator=(const _Self &_x) {
					_node = _x._node;
					_sentinel = _x._sentinel;
					return *this;
				}


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
					if (_node == NULL) {
						_node = static_cast<pointer>(_sentinel);
					}
					return *this;
				}

				_Self operator++(int) {
					_Self _Tmp = *this;
					++*this;
					return _Tmp;
				}

				_Self& operator--() {
					if (_node == _sentinel) {
						_node = _sentinel->left->max();
					}
					else if (_node->left != NULL) {
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

	template<class Node, class Node_Base>
		bool operator==(const bi_tree_iterator<Node, Node_Base>& _Left, const bi_tree_iterator<Node, Node_Base>& _Right) {
			return _Left.base() == _Right.base();
		}
	
	template<class Node, class Node_Base>
		bool operator!=(const bi_tree_iterator<Node, Node_Base>& _Left, const bi_tree_iterator<Node, Node_Base>& _Right) {
			return _Left.base() != _Right.base();
		}

	template<typename _Key, class _Pair, class _Compare, class _Alloc = std::allocator<ft::tree_node<_Pair> > >
	class BItree {

		public:

			typedef _Key key_type;
			typedef _Pair value_type;
			typedef std::size_t 				size_type;
			typedef std::ptrdiff_t 			difference_type;
			typedef _Alloc 				allocator_type;

			// node type
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef ft::tree_node<value_type> node_type;//??

			typedef ft::bi_tree_iterator<pointer, ft::tree_node_base<value_type>* > iterator;
			typedef ft::bi_tree_iterator<const_pointer, const ft::tree_node_base<value_type>* > const_iterator;

		
			pointer _root;
			ft::tree_node_base<value_type> _sentinel;
			_Alloc _alloc;
			_Compare _comp;

			BItree() : _root(NULL), _size(0), _sentinel() {
				_sentinel.left = static_cast<pointer>(&_sentinel);
			}

			BItree(const BItree& _X) : _root(NULL), _size(0) {
				_root = _copy_tree(_X._root);
				_comp = _X._comp;
				_size = _X._size;
				if (_root != NULL) {
					_sentinel.left = _root;
				}
				else {
					_sentinel.left = static_cast<pointer>(&_sentinel);
				}
			}

			BItree& operator=(const BItree& _X) {
				if (this != &_X) {
					clear(_root);
					_root = _copy_tree(_X._root);
					_comp = _X._comp;
					_size = _X._size;
					if (_root != NULL) {
						_sentinel.left = _root;
					}
					else {
						_sentinel.left = static_cast<pointer>(&_sentinel);
					}
				}
				return *this;
			}

			ft::pair<iterator, bool> insert(const value_type& val) {
				pointer curr = _root;
				iterator it = find(val.first);
				if (it != end()) { return ft::make_pair(it, false); }
				else if (_root == NULL) {
					_root = _new_node(val);
					curr = _root;
					_sentinel.left = _root;
				}
				else {
					while (curr != NULL) {
						if (_comp(val.first, curr->pair.first)) {
							if (curr->left == NULL) {
								curr->left = _new_node(val);
								curr->left->parent = curr;
								break;
							}
							else
								curr = curr->left;
						}
						else {
							if (curr->right == NULL) {
								curr->right =_new_node(val);
								curr->right->parent = curr;
								break;
							}
							else
								curr = curr->right;
						}
					}
				}
				++_size;
				return ft::make_pair(iterator(curr, &_sentinel), true);
			}

			void erase(iterator pos) {
				pointer curr = pos.base();//check if it is a valid iterator

				// if no child
				if (curr->left == NULL && curr->right == NULL) {
					if (curr->parent == NULL) {
						_delete_node(curr);//does root is null?
						--_size;
						_root = NULL;
						_sentinel.left = static_cast<pointer>(&_sentinel);
					}
					else {
						if (curr->parent->left == curr) {
							curr->parent->left = NULL;
						}
						else {
							curr->parent->right = NULL;
						}
						_delete_node(curr);
						--_size;
					}
				} // if one child
				else if (curr->left == NULL || curr->right == NULL) {
					if (curr->left == NULL) {
						if (curr->parent == NULL) {
							_root = curr->right;
							_root->parent = NULL;
							_sentinel.left = _root;
							_delete_node(curr);
							--_size;
						}
						else {
							if (curr->parent->left == curr) {
								curr->parent->left = curr->right;
								curr->right->parent = curr->parent;
								_delete_node(curr);
								--_size;
							}
							else {
								curr->parent->right = curr->right;
								curr->right->parent = curr->parent;
								_delete_node(curr);
								--_size;
							}
						}
					}
					else {
						if (curr->parent == NULL) {
							_root = curr->left;
							_root->parent = NULL;
							_sentinel.left = _root;
							_delete_node(curr);
							--_size;
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
								--_size;
							}
						}
					}
				}
				else {// if two children, not the best way to do it i think
					pointer succ = curr->right.min();
					value_type tmp(succ->pair.first, succ->pair.second);
					erase(iterator(succ));
					pointer newnode = _new_node(tmp);
					newnode->left = curr->left;
					if (newnode->left != NULL) {
						newnode->left->parent = newnode;
					}
					newnode->right = curr->right;
					if (newnode->right != NULL) {
						newnode->right->parent = newnode;
					}
					newnode->parent = curr->parent;
					if (curr->parent == NULL) {
						_root = newnode;
					}
					else {
						if (curr->parent->left == curr) {
							curr->parent->left = newnode;
						}
						else {
							curr->parent->right = newnode;
						}
					}
					_delete_node(curr);
				}
			}

			void erase(iterator first, iterator last) {
				while (first != last) {
					erase(first++);
				}
			}

			size_type erase(const key_type& key) {
				iterator it = find(key);
				if (it != end()) {
					erase(it);
					return 1;
				}
				return 0;
			}

			void clear() {
				_delete_tree(_root);
				_root = NULL;
				_size = 0;
			}

			iterator find(const key_type& k) {//do const one
				pointer node = _root;

				while (node != NULL) {
					if (k == node->pair.first) {
						return iterator(node, &_sentinel);
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
				return iterator(_root->min(), &_sentinel);
			}

			const_iterator begin() const {
				return const_iterator(_root->min(), &_sentinel);
			}

			iterator end() {
				return iterator(static_cast<pointer>(&_sentinel) ,&_sentinel);
			}

			const_iterator end() const {
				return const_iterator(static_cast<pointer>(&_sentinel), &_sentinel);
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
			
			size_type size() const {
				return _size;
			}

			bool empty() const {
				return _size == 0;
			}

			size_type max_size() const {
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
					if (x != NULL) {
						_alloc.destroy(x);
						_alloc.deallocate(x, 1);
						x = NULL;
					}
				}

				void _delete_tree(pointer x) {
					if (x != NULL) {
						_delete_tree(x->left);
						_delete_tree(x->right);
						_delete_node(x);
						_sentinel->left = static_cast<pointer>(&_sentinel);
					}
				}

				pointer _copy_tree(pointer x) {
					if (x == NULL) {
						return NULL;
					}
					pointer y = _new_node(x->pair);
					y->left = _copy_tree(x->left);
					if (y->left != NULL) {
						y->left->parent = y;
					}
					y->right = _copy_tree(x->right);
					if (y->right != NULL) {
						y->right->parent = y;
					}
					return y;
				}

				size_type _size;

	};
}

#endif