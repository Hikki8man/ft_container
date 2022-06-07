#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <memory>

namespace ft {

	template<class value_type>
	struct BInode {
		typedef BInode<value_type>* node_ptr;

		BInode(const value_type& value) : value(value), left(NULL), right(NULL), parent(NULL) {}
	
		value_type value;
		node_ptr left;
		node_ptr right;
		node_ptr parent;
	};

	template<typename _Key, typename _Val, typename _Alloc = std::allocator<_Val> >
	class BItree {

		protected:
			typedef BInode<_Val> node;
			node *_root;

		public:

			typedef _Key key_type;
			typedef _Val value_type;
			typedef _Alloc allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;

			BItree() : root(NULL) {}

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

	}
}

#endif