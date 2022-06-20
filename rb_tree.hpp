#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <memory>
#include "iterator_traits.hpp"
#include "pair.hpp"

namespace ft {

	// template<class Pair>
	// 	struct tree_node;

	// template<class value_type>
	// struct tree_node_base {

	// 	typedef tree_node<value_type>* node_ptr;

	// 	tree_node_base() : left(NULL), right(NULL), parent(NULL) {}

	// 	tree_node_base(const tree_node_base & src) {
	// 		left = src.left;
	// 		right = src.right;
	// 		parent = src.parent;
	// 	}

	// 	~tree_node_base() {}
	
	// 	tree_node_base &operator=(const tree_node_base &other) {
	// 		if (this != &other) {
	// 			left = other.left;
	// 			right = other.right;
	// 			parent = other.parent;
	// 		}
	// 		return *this;
	// 	}

	// 	node_ptr left;
	// 	node_ptr right;
	// 	node_ptr parent;

	// };

	// template<class Pair>
	// struct tree_node : public ft::tree_node_base<Pair> {

	// 	typedef ft::tree_node_base<Pair> base;
	// 	typedef tree_node<Pair>* node_ptr;

	// 	tree_node(const Pair &p = Pair()) : base(), pair(p), is_black(false) {}
	// 	tree_node(const tree_node & src) : base(src), pair(src.pair), is_black(src.is_black) {}
	// 	~tree_node() {}
	// 	tree_node &operator=(const tree_node &other) {
	// 		base::operator=(other);
	// 		pair = other.pair;
	// 		is_black = other.is_black;
	// 		return *this;
	// 	}

	// 	node_ptr next() {
	// 		if (this->right != NULL) {
	// 			node_ptr tmp = this->right;
	// 			while (tmp->left != NULL) {
	// 				tmp = tmp->left;
	// 			}
	// 			return tmp;
	// 		}
	// 		node_ptr tmp = this->parent;
	// 		node_ptr tmp2 = this;
	// 		while (tmp != NULL && tmp->right == tmp2) {
	// 			tmp2 = tmp;
	// 			tmp = tmp->parent;
	// 		}
	// 		return tmp;
	// 	}

	// 	node_ptr prev() {
	// 		if (this->left != NULL) {
	// 			node_ptr tmp = this->left;
	// 			while (tmp->right != NULL) {
	// 				tmp = tmp->right;
	// 			}
	// 			return tmp;
	// 		}
	// 		node_ptr tmp = this->parent;
	// 		node_ptr tmp2 = this;
	// 		while (tmp != NULL && tmp->left == tmp2) {
	// 			tmp2 = tmp;
	// 			tmp = tmp->parent;
	// 		}
	// 		return tmp;
	// 	}

	// 	node_ptr min() {
	// 		node_ptr tmp = this;
	// 		while (tmp->left != NULL) {
	// 			tmp = tmp->left;
	// 		}
	// 		return tmp;
	// 	}

	// 	node_ptr max() {
	// 		node_ptr tmp = this;
	// 		while (tmp->right != NULL) {
	// 			tmp = tmp->right;
	// 		}
	// 		return tmp;
	// 	}

	// 	Pair pair;
	// 	bool is_black;
	// };

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

template< class Node >
	class rb_tree_iterator {

			public:
				typedef typename ft::iterator_traits<Node>::value_type value_type;
				typedef typename ft::iterator_traits<Node>::reference reference;
				typedef typename ft::iterator_traits<Node>::pointer pointer;
				typedef typename ft::iterator_traits<Node>::difference_type difference_type;
				typedef ft::bidirectional_iterator_tag	iterator_category;

				typedef rb_tree_iterator<Node> _Self;

				pointer _node;
				pointer _sentinel;

				rb_tree_iterator() : _node(), _sentinel() {}

				rb_tree_iterator(pointer _x, pointer _s) : _node(_x), _sentinel(_s) {}
				template<class N>
				rb_tree_iterator(const rb_tree_iterator<N> &_x) : _node(_x._node), _sentinel(_x._sentinel) {}

				rb_tree_iterator& operator=(const _Self &_x) {
					_node = _x._node;
					_sentinel = _x._sentinel;
					return *this;
				}

				pointer base() const { return _node; }

				reference operator*() const { return *_node; }

				pointer operator->() const { return _node; }

				_Self& operator++() {
					if (_node) {
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
		bool operator==(const rb_tree_iterator<Node>& _Left, const rb_tree_iterator<Node>& _Right) {
			return _Left.base() == _Right.base();
		}
	
	template<class Node>
		bool operator!=(const rb_tree_iterator<Node>& _Left, const rb_tree_iterator<Node>& _Right) {
			return _Left.base() != _Right.base();
		}

	// template<class Node>
	// 	class const_rb_tree_iterator {

	// 		public:
	// 			typedef typename ft::iterator_traits<Node>::value_type value_type;
	// 			typedef typename ft::iterator_traits<Node>::reference reference;
	// 			typedef typename ft::iterator_traits<Node>::pointer pointer;
	// 			typedef typename ft::iterator_traits<Node>::difference_type difference_type;
	// 			typedef ft::bidirectional_iterator_tag	iterator_category;

	// 			typedef const_rb_tree_iterator<Node> _Self;

	// 			pointer _node;
	// 			pointer _sentinel;

	// 			const_rb_tree_iterator() : _node(), _sentinel() {}

	// 			const_rb_tree_iterator(pointer _x, pointer _s) : _node(_x), _sentinel(_s) {}

	// 			template<typename _Node>
	// 			const_rb_tree_iterator(const rb_tree_iterator<_Node> &_x) : _node(_x._node), _sentinel(_x._sentinel) {}

	// 			const_rb_tree_iterator& operator=(const _Self &_x) {
	// 				_node = _x._node;
	// 				_sentinel = _x._sentinel;
	// 				return *this;
	// 			}

	// 			pointer base() const { return _node; }

	// 			reference operator*() const { return *_node; }

	// 			pointer operator->() const { return _node; }

	// 			_Self& operator++() {
	// 				_node = _node->next();
	// 				if (_node == NULL) {
	// 					_node = _sentinel;
	// 				}
	// 				return *this;
	// 			}

	// 			_Self operator++(int) {
	// 				_Self _Tmp = *this;
	// 				++*this;
	// 				return _Tmp;
	// 			}

	// 			_Self& operator--() {
	// 				if (_node == _sentinel)
	// 					_node = _sentinel->left->max();
	// 				else
	// 					_node = _node->prev();
	// 				return *this;
	// 			}

	// 			_Self operator--(int) {
	// 				_Self _Tmp = *this;
	// 				--*this;
	// 				return _Tmp;
	// 			}

	// 			bool operator==(const _Self &_x) const {
	// 				return _node == _x._node;
	// 			}

	// 			bool operator!=(const _Self &_x) const {
	// 				return _node != _x._node;
	// 			}

	// 			reference operator[](difference_type _Off) const {
	// 				return *(_node + _Off);
	// 			}
	// 	};

	// template<class Node>
	// 	bool operator==(const const_rb_tree_iterator<Node>& _Left, const const_rb_tree_iterator<Node>& _Right) {
	// 		return _Left.base() == _Right.base();
	// 	}
	
	// template<class Node>
	// 	bool operator!=(const const_rb_tree_iterator<Node>& _Left, const const_rb_tree_iterator<Node>& _Right) {
	// 		return _Left.base() != _Right.base();
	// 	}


	template<typename _Key, class _Pair, class _Compare, class _Alloc = std::allocator<ft::tree_node<_Pair> > >
	class rb_tree {

		public:

			typedef _Key key_type;
			typedef _Pair value_type;
			typedef std::size_t 				size_type;
			typedef std::ptrdiff_t 			difference_type;
			typedef _Alloc 				allocator_type;
			typedef _Compare		 key_compare;

			// node type
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;


			typedef ft::rb_tree_iterator<pointer> iterator;
			typedef ft::rb_tree_iterator<const_pointer> const_iterator;

		
			pointer _root;
			tree_node<value_type> _sentinel;
			_Alloc _alloc;
			key_compare _comp;

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
					insert(first->pair);
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
				if (pos == end() || pos.base() == NULL) { return; }
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
					pointer succ = curr->right->min();
					value_type tmp(succ->pair.first, succ->pair.second);
					erase(iterator(succ, &_sentinel));
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

			size_t count(const key_type& k) const {
				return find(k) == end() ? 0 : 1;
			}

			iterator begin() {
				pointer beg = _root->min();
				if (beg == NULL)
					beg = &_sentinel;
				return iterator(beg, &_sentinel);
			}

			const_iterator begin() const {
				pointer beg = _root->min();
				if (beg == NULL)
					beg = &_sentinel;
				return const_iterator(beg, &_sentinel);
			}

			iterator end() {
				return iterator(&_sentinel ,&_sentinel);
			}

			const_iterator end() const {
				return const_iterator(&_sentinel, &_sentinel);
			}

			iterator lower_bound(const key_type& k) {
				iterator it = begin();
				for (; it != end() && _comp(it->pair.first, k); ++it);
				return it;
			}

			const_iterator lower_bound(const key_type& k) const {
				const_iterator it = begin();
				for (; it != end() && _comp(it->pair.first, k); ++it);
				return it;
			}

			iterator upper_bound(const key_type& k) {
				iterator it = begin();
				for (; it != end() && !_comp(k, it->pair.first); it++);
				return it;
			}

			const_iterator upper_bound(const key_type& k) const {
				const_iterator it = begin();
				for (; it != end() && !_comp(k, it->pair.first); it++);
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

				size_type _size;

	};
}

#endif