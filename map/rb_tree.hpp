#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <memory>
#include "../utils/iterator_traits.hpp"
#include "../utils/pair.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../utils/equal.hpp"
#include "../utils/lexicographical_compare.hpp"

namespace ft {

	//TREE NODE BASE=========================================================================================================
	struct tree_node_base {

		typedef tree_node_base* node_ptr;

		tree_node_base() : is_black(false), parent(NULL), left(NULL), right(NULL) {}
		tree_node_base(const tree_node_base & src) : is_black(src.is_black), parent(src.parent), left(src.left), right(src.right) {}
		~tree_node_base() {}
		tree_node_base &operator=(const tree_node_base &other) {
			parent = other.parent;
			left = other.left;
			right = other.right;
			is_black = other.is_black;
			return *this;
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

		node_ptr parent;
		node_ptr left;
		node_ptr right;
		bool is_black;
	};

	// TREE NODE=============================================================================================================
	template <class _Pair>
	class tree_node : public tree_node_base {
		public:
			tree_node(const _Pair& val = _Pair()) : tree_node_base(), pair(val) {}
			tree_node(const tree_node & src) : tree_node_base(src), pair(src.pair) {}
			tree_node &operator=(const tree_node &other) {
				tree_node_base::operator=(other);
				pair = other.pair;
				return *this;
			}
			_Pair pair;
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
				typedef tree_node_base* _Base_ptr;
				typedef tree_node<_Pair>* _Node_ptr;

				_Base_ptr _node;
				const _Base_ptr _sentinel;

				rb_tree_iterator() : _node(), _sentinel() {}

				rb_tree_iterator(_Base_ptr _x, _Base_ptr _s) : _node(_x), _sentinel(_s) {}

				rb_tree_iterator& operator=(const _Self &_x) {
					_node = _x._node;
					return *this;
				}

				reference operator*() const { return static_cast<_Node_ptr>(_node)->pair; }

				pointer operator->() const { return &static_cast<_Node_ptr>(_node)->pair; }

				_Self& operator++() {
					if (_node) {
						if (_node->right != NULL) {
							_node = _node->right;
							while (_node->left != NULL) {
								_node = _node->left;
							}
						}
						else {
							_Base_ptr _y = _node->parent;
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
						_Base_ptr _y = _node->parent;
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
				typedef const tree_node_base* _Base_ptr;
				typedef const tree_node<_Pair>* _Node_ptr;
			
				_Base_ptr _node;
				_Base_ptr _sentinel;

				rb_tree_const_iterator() : _node(), _sentinel() {}

				rb_tree_const_iterator(_Base_ptr _x, _Base_ptr _s) : _node(_x), _sentinel(_s) {}

				rb_tree_const_iterator(const iterator &_x) : _node(_x._node), _sentinel(_x._sentinel) {}

				rb_tree_const_iterator& operator=(const _Self &_x) {
					_node = _x._node;
					return *this;
				}

				reference operator*() const { return static_cast<_Node_ptr>(_node)->pair; }

				pointer operator->() const { return &static_cast<_Node_ptr>(_node)->pair; }

				_Self& operator++() {
					if (_node) {
						if (_node->right != NULL) {
							_node = _node->right;
							while (_node->left != NULL) {
								_node = _node->left;
							}
						}
						else {
							_Base_ptr _y = _node->parent;
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
						_Base_ptr _y = _node->parent;
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
			typedef ft::tree_node_base* _Base_ptr;
			typedef const ft::tree_node_base* _Const_base_ptr;

			_Base_ptr _root;
			ft::tree_node_base _sentinel;
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
				_Base_ptr curr = _root;
				bool bol = true;

				if (_root == NULL) {
					_root = _new_node(val);
					curr = _root;
					_sentinel.left = _root;
					++_size;
				}
				else {
					size_type size_before = _size;
					curr = _insert_from_pos(_root, val);
					if (size_before == _size) {
						bol = false;
					} 
				}
				if (curr->parent == NULL) {
					curr->is_black = true;
				}
				else if (curr->parent->parent) {
					insertFix(curr);
				}
				return ft::make_pair(iterator(curr, &_sentinel), bol);
			}

			iterator insert (iterator position, const value_type& val)
			{
				_Base_ptr to_ret = NULL;
				if (begin() == end())
					return insert(val).first;
				if (position == end()) {
					--position;
				}
				iterator tmp = position;
				if (_comp(val.first, position->first)) {
					--tmp;
					while (tmp._node && _comp(val.first, tmp->first)) {
						--tmp;
						--position;
					}
					to_ret = _insert_from_pos(position._node, val);
				}
				else {
					++tmp;
					while (tmp != end() && !_comp(val.first, tmp->first)) {
						++tmp;
						++position;
					}
					to_ret =  _insert_from_pos(position._node, val);
				}
				if (to_ret->parent == NULL) 
					to_ret->is_black = true;
				else if (to_ret->parent->parent)
					insertFix(to_ret);

				return iterator(to_ret, &_sentinel);
			}

			template<class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				for (; first != last; ++first) {
					insert(*first);
				}
			}

			void left_rotate(_Base_ptr x) {
				_Base_ptr y = x->right;
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

			void right_rotate(_Base_ptr x) {
				_Base_ptr y = x->left;
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

			void insertFix(_Base_ptr k) {
				_Base_ptr u;
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
				_Base_ptr curr = pos._node;

				// if no childs
				if (curr->left == NULL && curr->right == NULL) {
					if (curr->parent == NULL) {
						_root = NULL;
						_sentinel.left = &_sentinel;
					}
					else {
						if (curr->parent->left == curr) {
							curr->parent->left = NULL;
						}
						else
							curr->parent->right = NULL;
					}
				} // if one child
				else if (curr->left == NULL || curr->right == NULL) {
					if (curr->left == NULL) {
						if (curr->parent == NULL) {
							_root = curr->right;
							_root->parent = NULL;
							_sentinel.left = _root;
						}
						else {
							if (curr->parent->left == curr) {
								curr->parent->left = curr->right;
								curr->right->parent = curr->parent;
							}
							else {
								curr->parent->right = curr->right;
								curr->right->parent = curr->parent;
							}
						}
					}
					else {
						if (curr->parent == NULL) {
							_root = curr->left;
							_root->parent = NULL;
							_sentinel.left = _root;
						}
						else {
							if (curr->parent->left == curr) {
								curr->parent->left = curr->left;
								curr->left->parent = curr->parent;
							}
							else {
								curr->parent->right = curr->left;
								curr->left->parent = curr->parent;
							}
						}
					}
				} // if two childs
				else {
					_Base_ptr succ = curr->right;
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
				}
				_delete_node(static_cast<pointer>(curr));
				--_size;
			}

			void erase(iterator first, iterator last) {
				if (first == begin() && last == end())
					clear();
				else {
					while (first != last) {
						erase(first++);
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
				_Base_ptr node = _root;

				while (node != NULL) {
					if (!_comp(static_cast<pointer>(node)->pair.first, k) && !_comp(k, static_cast<pointer>(node)->pair.first)) {
						return iterator(node, &_sentinel);
					}
					else if (_comp(k, static_cast<pointer>(node)->pair.first)) {
						node = node->left;
					}
					else {
						node = node->right;
					}
				}
				return end();
			}

			const_iterator find(const key_type& k) const {
				_Base_ptr node = _root;

				while (node != NULL) {
					if (!_comp(static_cast<pointer>(node)->pair.first, k) && !_comp(k, static_cast<pointer>(node)->pair.first)) {
						return const_iterator(node, &_sentinel);
					}
					else if (_comp(k, static_cast<pointer>(node)->pair.first)) {
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
				return _lower_bound(k);
			}

			const_iterator lower_bound(const key_type& k) const {
				return const_iterator(_lower_bound(k));
			}
			// Upper Bound===================================================================================================

			iterator upper_bound(const key_type& k) {
				return _upper_bound(k);
			}

			const_iterator upper_bound(const key_type& k) const {
				return const_iterator(_upper_bound(k));
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

				_Base_ptr _new_node(const value_type& val) {
					pointer _x = _alloc.allocate(1);
					_alloc.construct(_x, val);
					return _x;
				}

				iterator _lower_bound(const key_type& k) {
					_Base_ptr node = _root;
					_Base_ptr previous = NULL;

					while (node != NULL) {
						previous = node;
						if (!_comp(static_cast<pointer>(node)->pair.first, k) && !_comp(k, static_cast<pointer>(node)->pair.first)) {
							return iterator(node, &_sentinel);
						}
						else if (_comp(k, static_cast<pointer>(node)->pair.first)) {
							node = node->left;
						}
						else {
							node = node->right;
						}
					}
					if (previous && !_comp(static_cast<pointer>(previous)->pair.first, k))
						return iterator(previous, &_sentinel);
					iterator it = iterator(previous, &_sentinel);
					return ++it;
				}

				iterator _upper_bound(const key_type& k) {
					_Base_ptr node = _root;
					_Base_ptr previous = NULL;

					while (node != NULL) {
						previous = node;
						if (!_comp(static_cast<pointer>(node)->pair.first, k) && !_comp(k, static_cast<pointer>(node)->pair.first)) {
							iterator ret = iterator(node, &_sentinel);
							return ++ret;
						}
						else if (_comp(k, static_cast<pointer>(node)->pair.first)) {
							node = node->left;
						}
						else {
							node = node->right;
						}
					}
					if (previous && !_comp(static_cast<pointer>(previous)->pair.first, k))
						return iterator(previous, &_sentinel);
					iterator it = iterator(previous, &_sentinel);
					return ++it;
				}

				_Base_ptr _insert_from_pos(_Base_ptr pos, const value_type& val) {
					_Base_ptr y = NULL;
					_Base_ptr p = pos;

					while (p != NULL) {
						if (!_comp(val.first, static_cast<pointer>(p)->pair.first) && !_comp(static_cast<pointer>(p)->pair.first, val.first))
							return p;

						y = p;
						if (_comp(val.first, static_cast<pointer>(p)->pair.first))
							p = p->left;
						else
							p = p->right;
					}
					if (y == NULL)
						return _root;
					++_size;
					if (_comp(val.first, static_cast<pointer>(y)->pair.first)) {
						y->left = _new_node(val);
						y->left->parent = y;
						return y->left;
					}
					else {
						y->right = _new_node(val);
						y->right->parent = y;
						return y->right;
					}
				}

				void _delete_node(pointer x) {
					if (x != NULL) {
						_alloc.destroy(x);
						_alloc.deallocate(x, 1);
						x = NULL;
					}
				}

				void _delete_tree(_Base_ptr x) {
					if (x != NULL) {
						_delete_tree(x->left);
						_delete_tree(x->right);
						_delete_node(static_cast<pointer>(x));
						_sentinel.left = &_sentinel;
					}
				}

				_Base_ptr _copy_tree(_Base_ptr x) {
					if (x == NULL) {
						return NULL;
					}
					_Base_ptr y = _new_node(static_cast<pointer>(x)->pair);
					y->is_black = x->is_black;
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
				operator<(const rb_tree& _l, const rb_tree& _r) {
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


		//Sert juste pour la fonctions qui print l'arbre
		// public:
		// 	struct Trunk
		// 	{
		// 		Trunk *prev;
		// 		std::string str;
			
		// 		Trunk(Trunk *prev, std::string str)
		// 		{
		// 			this->prev = prev;
		// 			this->str = str;
		// 		}
		// 	};

		// 	void showTrunks(Trunk *p)
		// 	{
		// 		if (p == nullptr)
		// 			return;
		// 		showTrunks(p->prev);
		// 		std::cout << p->str;
		// 	}

		// 	void printTree(pointer root, Trunk *prev, bool isLeft)
		// 	{
		// 		if (root == nullptr)
		// 			return;
		// 		std::string prev_str = "    ";
		// 		Trunk *trunk = new Trunk(prev, prev_str);
			
		// 		printTree(static_cast<pointer>(root->right), trunk, true);
			
		// 		if (!prev)
		// 			trunk->str = "———";
		// 		else if (isLeft)
		// 		{
		// 			trunk->str = "┌———";
		// 			prev_str = "    |";
		// 		}
		// 		else {
		// 			trunk->str = "└──";
		// 			prev->str = prev_str;
		// 		}
			
		// 		showTrunks(trunk);
		// 		if (root->is_black == false)
		// 			std::cout << "\033[31m" << root->pair.first << "\033[0m" << std::endl;
		// 		else
		// 			std::cout << root->pair.first << std::endl;
					
		// 		if (prev) {
		// 			prev->str = prev_str;
		// 		}
		// 		trunk->str = "    |";
			
		// 		printTree(static_cast<pointer>(root->left), trunk, false);
		// 	}

		// 	void print()
		// 	{
		// 		printTree(static_cast<pointer>(_root), NULL, false);
		// 	}
	};
}

#endif