#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <memory>
#include "iterator_traits.hpp"
#include "pair.hpp"
#include "reverse_iterator.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

namespace ft {

	//Node===================================================================================================================
	template<class Pair>
	struct tree_node {

		typedef tree_node<Pair>* node_ptr;

		tree_node(const Pair &p = Pair()) : pair(p), is_black(false), parent(NULL), left(NULL), right(NULL) {}
		tree_node(const tree_node & src) : pair(src.pair), is_black(src.is_black), parent(src.parent), left(src.left), right(src.right) {}
		~tree_node() {}
		tree_node &operator=(const tree_node &other) {
			pair = other.pair;
			parent = other.parent;
			left = other.left;
			right = other.right;
			is_black = other.is_black;
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
			node_ptr tmp2 = this;
			while (tmp != NULL && tmp->right == tmp2) {
				tmp2 = tmp;
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
			node_ptr tmp2 = this;
			while (tmp != NULL && tmp->left == tmp2) {
				tmp2 = tmp;
				tmp = tmp->parent;
			}
			return tmp;
		}

		node_ptr min() {
			node_ptr tmp = this;
			while (tmp && tmp->left != NULL) {
				tmp = tmp->left;
			}
			return tmp;
		}

		node_ptr max() {
			node_ptr tmp = this;
			while (tmp && tmp->right != NULL) {
				tmp = tmp->right;
			}
			return tmp;
		}

		Pair pair;
		node_ptr parent;
		node_ptr left;
		node_ptr right;
		bool is_black;
	};

// TREE ITERATOR=============================================================================================================
template< class _Pair >
	class rb_tree_iterator {

			public:
				typedef _Pair value_type;
				typedef _Pair& reference;
				typedef _Pair* pointer;

				typedef typename std::ptrdiff_t difference_type;
				typedef ft::bidirectional_iterator_tag	iterator_category;

				typedef rb_tree_iterator<_Pair> _Self;
				typedef tree_node<_Pair>* _Node_ptr;

				_Node_ptr _node;
				_Node_ptr _sentinel;

				rb_tree_iterator() : _node(), _sentinel() {}

				rb_tree_iterator(_Node_ptr _x, _Node_ptr _s) : _node(_x), _sentinel(_s) {}

				rb_tree_iterator& operator=(const _Self &_x) {
					_node = _x._node;
					_sentinel = _x._sentinel;
					return *this;
				}

				_Node_ptr base() const { return _node; }

				reference operator*() const { return _node->pair; }

				pointer operator->() const { return &_node->pair; }

				_Self& operator++() {
					if (_node) {
						if (_node->right != NULL) {
							_node = _node->right;
							while (_node->left != NULL) {
								_node = _node->left;
							}
						}
						else {
							_Node_ptr _y = _node->parent;
							while (_y != NULL && _node == _y->right) {
								_node = _y;
								_y = _y->parent;
							}
							_node = _y;
						}
					}
					if (_node == NULL) {
						_node = _sentinel;
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
						_Node_ptr _y = _node->parent;
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

				friend bool
				operator==(const _Self& _l, const _Self& _r) { return _l._node == _r._node; }

				friend bool
				operator!=(const _Self& _l, const _Self& _r) { return _l._node != _r._node; }
	};

// TREE CONST ITERATOR=======================================================================================================
	template< class _Pair >
	class rb_tree_const_iterator {

			public:
				typedef _Pair value_type;
				typedef const _Pair& reference;
				typedef const _Pair* pointer;

				typedef rb_tree_iterator<_Pair> iterator;

				typedef typename std::ptrdiff_t difference_type;
				typedef ft::bidirectional_iterator_tag	iterator_category;

				typedef rb_tree_const_iterator<_Pair> _Self;
				typedef const tree_node<_Pair>* _Node_ptr;
			
				_Node_ptr _node;
				_Node_ptr _sentinel;

				rb_tree_const_iterator() : _node(), _sentinel() {}

				rb_tree_const_iterator(_Node_ptr _x, _Node_ptr _s) : _node(_x), _sentinel(_s) {}

				rb_tree_const_iterator(const iterator &_x) : _node(_x._node), _sentinel(_x._sentinel) {}

				rb_tree_const_iterator& operator=(const _Self &_x) {
					_node = _x._node;
					_sentinel = _x._sentinel;
					return *this;
				}

				_Node_ptr base() const { return _node; }

				reference operator*() const { return _node->pair; }

				pointer operator->() const { return &_node->pair; }

				_Self& operator++() {
					if (_node) {
						if (_node->right != NULL) {
							_node = _node->right;
							while (_node->left != NULL) {
								_node = _node->left;
							}
						}
						else {
							_Node_ptr _y = _node->parent;
							while (_y != NULL && _node == _y->right) {
								_node = _y;
								_y = _y->parent;
							}
							_node = _y;
						}
					}
					if (_node == NULL) {
						_node = _sentinel;
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
						_Node_ptr _y = _node->parent;
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

				friend bool
				operator==(const _Self& _l, const _Self& _r) { return _l._node == _r._node; }

				friend bool
				operator!=(const _Self& _l, const _Self& _r) { return _l._node != _r._node; }
	};

//	TREE=====================================================================================================================
	template<typename _Key, class _Pair, class _Compare, class _Alloc = std::allocator<ft::tree_node<_Pair> > >
	class rb_tree {

		public:

			typedef _Key key_type;
			typedef _Pair value_type;
			typedef std::size_t 				size_type;
			typedef std::ptrdiff_t 			difference_type;
			typedef _Alloc 				allocator_type;
			typedef _Compare		 key_compare;


			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;


			typedef ft::rb_tree_iterator<value_type> iterator;
			typedef ft::rb_tree_const_iterator<value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;


		protected:
			pointer _root;
			tree_node<value_type> _sentinel;
			_Alloc _alloc;
			key_compare _comp;
			size_type _size;

		public:
			rb_tree() : _root(NULL), _size(0), _sentinel() {
				_sentinel.left = &_sentinel;
			}

			rb_tree(const rb_tree& _X) : _root(NULL), _size(0) {
				_root = _copy_tree(_X._root);
				_comp = _X._comp;
				_size = _X._size;
				if (_root != NULL) {
					_sentinel.left = _root;
				}
				else {
					_sentinel.left = &_sentinel;
				}
			}

			rb_tree& operator=(const rb_tree& _X) {
				if (this != &_X) {
					this->clear();
					_root = _copy_tree(_X._root);
					_comp = _X._comp;
					_size = _X._size;
					if (_root != NULL) {
						_sentinel.left = _root;
					}
					else {
						_sentinel.left = &_sentinel;
					}
				}
				return *this;
			}

			~rb_tree() {
				_delete_tree(_root);
			}

			key_compare key_comp() const {
				return _comp;
			}

			// INSERT========================================================================================================

			ft::pair<iterator, bool> insert(const value_type& val) {
				pointer curr = _root;
				pointer to_ret = NULL;
				iterator it = find(val.first);
				if (it != end()) { return ft::make_pair(it, false); }
				else if (_root == NULL) {
					_root = _new_node(val);
					curr = _root;
					_sentinel.left = _root;
					to_ret = _root;
				}
				else {
					while (curr != NULL) {
						if (_comp(val.first, curr->pair.first)) {
							if (curr->left == NULL) {
								curr->left = _new_node(val);
								curr->left->parent = curr;
								to_ret = curr->left;
								break;
							}
							else
								curr = curr->left;
						}
						else {
							if (curr->right == NULL) {
								curr->right =_new_node(val);
								curr->right->parent = curr;
								to_ret = curr->right;
								break;
							}
							else
								curr = curr->right;
						}
					}
				}
				++_size;
				if (to_ret->parent == NULL) {
					to_ret->is_black = true;
				}
				else if (to_ret->parent->parent) {
					insertFix(to_ret);
				}

				return ft::make_pair(iterator(to_ret, &_sentinel), true);
			}

			iterator insert(iterator hint, const value_type& val) {
				pointer _hint = hint.base();
				pointer to_ret = NULL;
				if (_hint == &_sentinel || _hint == NULL || _hint->parent == NULL) {
					return insert(val).first;
				} // if _hint is left child of its parent and val to insert is greater than parent value then recall insert with parent
				else if (_hint->parent->left == _hint && !_comp(val.first, _hint->parent->pair.first)) {
					std::cout << "insert left" << std::endl;
					to_ret = insert(iterator(_hint->parent, &_sentinel), val).base();
				} // if _hint is right child of its parent and val to insert is less than parent value then recall insert with parent
				else if (_hint->parent->right == _hint && _comp(val.first, _hint->parent->pair.first)) {
					std::cout << "insert right" << std::endl;
					to_ret = insert(iterator(_hint->parent, &_sentinel), val).base();
				}
				else {
					while (_hint != NULL) {
						if (_hint->pair.first == val.first) {
							return iterator(_hint, &_sentinel);
						}
						else if (_comp(val.first, _hint->pair.first)) {
							if (_hint->left == NULL) {
								_hint->left = _new_node(val);
								_hint->left->parent = _hint;
								to_ret = _hint->left;
								++_size;
								break;
							}
							else
								_hint = _hint->left;
						}
						else {
							if (_hint->right == NULL) {
								_hint->right = _new_node(val);
								_hint->right->parent = _hint;
								to_ret = _hint->right;
								++_size;
								break;
							}
							else
								_hint = _hint->right;
						}
					}
				}
				return iterator(to_ret, &_sentinel);
			}

			template<class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				for (; first != last; ++first) {
					insert(*first);
				}
			}

			void left_rotate(pointer x) {
				pointer y = x->right;
				x->right = y->left;
				if (y->left != NULL) {
					y->left->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == NULL) {
					_root = y;
				}
				else if (x == x->parent->left) {
					x->parent->left = y;
				}
				else {
					x->parent->right = y;
				}
				y->left = x;
				x->parent = y;
			}

			void right_rotate(pointer x) {
				pointer y = x->left;
				x->left = y->right;
				if (y->right != NULL) {
					y->right->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == NULL) {
					_root = y;
				}
				else if (x == x->parent->right) {
					x->parent->right = y;
				}
				else {
					x->parent->left = y;
				}
				y->right = x;
				x->parent = y;
			}

			void insertFix(pointer k) {
				pointer u;
				while (k->parent != NULL && k->parent->is_black == false) {
					if (k->parent == k->parent->parent->left) {
						u = k->parent->parent->right;
						if (u != NULL && u->is_black == false) {
							k->parent->is_black = true;
							u->is_black = true;
							k->parent->parent->is_black = false;
							k = k->parent->parent;
						}
						else {
							if (k == k->parent->right) {
								k = k->parent;
								left_rotate(k);
							}
							k->parent->is_black = true;
							k->parent->parent->is_black = false;
							right_rotate(k->parent->parent);
						}
					}
					else {
						u = k->parent->parent->left;
						if (u != NULL && u->is_black == false) {
							k->parent->is_black = true;
							u->is_black = true;
							k->parent->parent->is_black = false;
							k = k->parent->parent;
						}
						else {
							if (k == k->parent->left) {
								k = k->parent;
								right_rotate(k);
							}
							k->parent->is_black = true;
							k->parent->parent->is_black = false;
							left_rotate(k->parent->parent);
						}
					}
					if (k == _root) {
						break;
					}
				}
				_root->is_black = true;
			}


			// Erase=========================================================================================================

			void erase(iterator pos) {
				pointer curr = pos.base();

				// if no child
				// std::cout << curr->pair.first << std::endl;
				// if (curr->left)
				// 	std::cout << "left: " << curr->left->pair.first << std::endl;
				// else
				// 	std::cout << "no left" << std::endl;
				// if (curr->right)
				// 	std::cout << "right: " << curr->right->pair.first << std::endl;
				// else
				// 	std::cout << "no right" << std::endl;
				// if (curr->parent)
				// 	std::cout << "parent: " << curr->parent->pair.first << std::endl;
				// else
				// 	std::cout << "no parent" << std::endl;


				if (curr->left == NULL && curr->right == NULL) {
					// std::cout << "no child" << std::endl;
					if (curr->parent == NULL) {
						_delete_node(curr);
						--_size;
						_root = NULL;
						_sentinel.left = &_sentinel;
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
					// std::cout << "one child" << std::endl;
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
				else {
					pointer succ = curr->right;
					// std::cout << "two childs" << std::endl;
					// if right subtree doesnt have left branch
					if (succ->left == NULL) {
						succ->left = curr->left;
						curr->left->parent = succ;
						succ->parent = curr->parent;
						if (curr->parent == NULL) {
							_root = succ;
							_sentinel.left = _root;
						}
						else {
							if (curr->parent->left == curr)
								curr->parent->left = succ;
							else
								curr->parent->right = succ;
						}
					}
					else {
						succ = succ->min();
						// if succ has a right child, attach it to parent
						if (succ->right) {
							succ->right->parent = succ->parent;
							succ->parent->left = succ->right;
						}
						else
							succ->parent->left = NULL;
						
						succ->left = curr->left;
						succ->left->parent = succ;
						succ->right = curr->right;
						succ->right->parent = succ;
						succ->parent = curr->parent;
						// std::cout << "succ parent: " << succ->parent->pair.first << std::endl;
						// std::cout << "succ left: " << succ->left->pair.first << std::endl;
						// std::cout << "succ right: " << succ->right->pair.first << std::endl;
						if (curr->parent == NULL) {
							_root = succ;
							_sentinel.left = _root;
						}
						else {
							if (curr->parent->left == curr)
								curr->parent->left = succ;
							else
								curr->parent->right = succ;
						}
					}
					_delete_node(curr);
					--_size;
				}
			}

			void erase(iterator first, iterator last) {
				if (first == begin() && last == end())
					clear();
				else {
					// iterator tmp(first);
					while (first != last) {
						// tmp = ++first;
						erase(first++);

						// first = tmp;
					}
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

			// Clear=========================================================================================================

			void clear() {
				_delete_tree(_root);
				_root = NULL;
				_size = 0;
			}

			// Find==========================================================================================================

			iterator find(const key_type& k) {
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
						return const_iterator(node, &_sentinel);
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

			// Bi Iterator
			iterator begin() {
				return iterator(_root != NULL ? _root->min() : &_sentinel, &_sentinel);
			}

			const_iterator begin() const {
				return const_iterator(_root != NULL ? _root->min(): &_sentinel, &_sentinel);
			}

			iterator end() {
				return iterator(&_sentinel ,&_sentinel);
			}

			const_iterator end() const {
				return const_iterator(&_sentinel, &_sentinel);
			}

			// Reverse Iterator==============================================================================================
			reverse_iterator rbegin() {
				return reverse_iterator(end());
			}

			reverse_iterator rend() {
				return reverse_iterator(begin());
			}

			// Lower Bound===================================================================================================
			iterator lower_bound(const key_type& k) {
				iterator it = begin();
				for (; it != end() && _comp(it->first, k); ++it);
				return it;
			}

			const_iterator lower_bound(const key_type& k) const {
				const_iterator it = begin();
				for (; it != end() && _comp(it->first, k); ++it);
				return it;
			}
			// Upper Bound===================================================================================================

			iterator upper_bound(const key_type& k) {
				iterator it = begin();
				for (; it != end() && !_comp(k, it->first); it++);
				return it;
			}

			const_iterator upper_bound(const key_type& k) const {
				const_iterator it = begin();
				for (; it != end() && !_comp(k, it->first); it++);
				return it;
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
						_sentinel.left = &_sentinel;
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

				// Compare===================================================================================================

				friend bool
				operator==(const rb_tree& _l, const rb_tree& _r) {
					return _l.size() == _r.size() && ft::equal(_l.begin(), _l.end(), _r.begin(), _r.end());
				}

				friend bool
				operator<(const rb_tree& _l, const rb_tree& _r) {// add compare ?
					return ft::lexicographical_compare(_l.begin(), _l.end(), _r.begin(), _r.end());
				}

				friend bool
				operator!=(const rb_tree& _l, const rb_tree& _r)
				{ return !(_l == _r); }

				friend bool
				operator>(const rb_tree& _l, const rb_tree& _r)
				{ return _r < _l; }

				friend bool
				operator<=(const rb_tree& _l, const rb_tree& _r)
				{ return !(_r < _l); }

				friend bool
				operator>=(const rb_tree& _l, const rb_tree& _r)
				{ return !(_l < _r); }
	};
}

#endif