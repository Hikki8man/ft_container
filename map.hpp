#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include "pair.hpp"
// #include "binary_tree.hpp"
#include "rb_tree.hpp"

namespace ft {

	template< class _Key, class _T, class _Compare = std::less<_Key>, class _Alloc = std::allocator<ft::pair<const _Key, _T> > >
	class map {
		public:

			typedef _Key                           key_type;
			typedef _T                             mapped_type;
			typedef ft::pair<const _Key, _T>       value_type;
			typedef _Compare                       key_compare;
			typedef _Alloc                         allocator_type;

			
		private:

		protected:
			typedef rb_tree<key_type, value_type, key_compare> _Red_type;
			key_compare _comp;
			allocator_type _alloc;

		public:
			_Red_type _tree;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename _Red_type::iterator iterator;
			typedef typename _Red_type::const_iterator const_iterator;
			typedef typename _Red_type::size_type size_type;
			typedef typename _Red_type::difference_type difference_type;

			//what todo with thooose
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree() {}

			template<class InputIterator>
			map(InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree() {
				for(; first != last; ++first) {
					insert(first);
				}
			 }

			map(const map& m) : _alloc(m.get_allocator()), _comp(key_comp()), _tree(m._tree) {}

			map &operator=(const map& m) {
				if(this != &m) {
					_tree = m._tree;
					_comp = m._comp;
					_alloc = m._alloc;
				}
				return *this;
			}

			~map() { clear(); }

			// Capacity======================================================================================================

			bool empty() const {
				return _tree.empty();
			}

			size_type size() const {
				return _tree.size();
			}

			size_type max_size() const {
				return _tree.max_size();
			}

			// Modifiers=====================================================================================================

			ft::pair<iterator, bool> insert(const value_type& value) {
				return _tree.insert(value);
			}

			iterator insert(iterator hint, const value_type& value) {
				return _tree.insert(hint, value);
			}

			template<class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				_tree.insert(first, last);
			}

			void erase(iterator position) {
				_tree.erase(position);
			}

			size_type erase(const key_type& key) {
				return _tree.erase(key);
			}

			void erase(iterator first, iterator last) {
				_tree.erase(first, last);
			}

			void clear() {
				_tree.clear();
			}

			void swap(map& m) {
				_Red_type tmp = _tree;
				_tree = m._tree;
				m._tree = tmp;
			}


			// Observers=====================================================================================================

			key_compare key_comp() const {
				return _tree.key_comp();
			}




			// Iterator======================================================================================================

			iterator begin() {
				return iterator(_tree.begin());
			}

			const_iterator begin() const {
				return const_iterator(_tree.begin());
			}

			iterator end() {
				return iterator(_tree.end());
			}

			const_iterator end() const {
				return const_iterator(_tree.end());
			}

			// Element access================================================================================================

			mapped_type& operator[](const key_type& key) {
				iterator it = lower_bound(key);

				if (it == end() || key_comp()(key, it->first))
					it = insert(it, value_type(key, mapped_type()));
				return it->second;
			}

			mapped_type& at(const key_type& key) {
				iterator it = find(key);
				if (it == end())
					throw std::out_of_range("map::at");
				return it->second;
			}

			// Lookup========================================================================================================

			iterator find(const key_type& key) {
				return iterator(_tree.find(key));
			}

			const_iterator find(const key_type& key) const {
				return const_iterator(_tree.find(key));
			}

			size_type count(const key_type& key) const {
				// return _tree.count(key);
				return find(key) == end() ? 0 : 1;
			}

			iterator lower_bound(const key_type& key) {
				return iterator(_tree.lower_bound(key));
			}

			const_iterator lower_bound(const key_type& key) const {
				return const_iterator(_tree.lower_bound(key));
			}

			iterator upper_bound(const key_type& key) {
				return iterator(_tree.upper_bound(key));
			}

			const_iterator upper_bound(const key_type& key) const {
				return const_iterator(_tree.upper_bound(key));
			}

			ft::pair<iterator, iterator> equal_range(const key_type& key) {
				return ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
			}

			ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
				return ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));
			}

			// Allocator=====================================================================================================

			allocator_type get_allocator() const {
				return _alloc;//non?
			}
	};
}

#endif