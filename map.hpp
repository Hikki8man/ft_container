#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include "pair.hpp"
#include "binary_tree.hpp"

namespace ft {

	template<class Pair, class Iter>
	class map_iterator {
		
		public:

			typedef typename ft::iterator_traits<Pair>::value_type value_type;
			typedef typename ft::iterator_traits<Pair>::pointer pointer;
			typedef typename ft::iterator_traits<Pair>::reference reference;
			typedef typename ft::iterator_traits<Pair>::difference_type difference_type;
			typedef typename ft::bidirectional_iterator_tag iterator_category;

		private:
			Iter _current;

		public:
			map_iterator() : _current() {}
			map_iterator(Iter it) : _current(it) {}
			template<class P, class I>
			map_iterator(const map_iterator<P, I>& it) : _current(it.base()) {}
			~map_iterator() {}

			map_iterator& operator=(const map_iterator& it) {
				_current = it.base();
				return *this;
			}

			Iter base() const {
				return _current;
			}

			reference operator*() const {
				return *_current->pair;
			}

			pointer operator->() const {
				return &_current->pair;
			}

			map_iterator& operator++() {
				++_current;
				return *this;
			}

			map_iterator operator++(int) {
				map_iterator tmp(*this);
				++_current;
				return tmp;
			}

			map_iterator& operator--() {
				--_current;
				return *this;
			}

			map_iterator operator--(int) {
				map_iterator tmp(*this);
				--_current;
				return tmp;
			}
	};

	template<class Pair, class Iter>
	bool operator==(const map_iterator<Pair, Iter>& it1, const map_iterator<Pair, Iter>& it2) {
		return it1.base() == it2.base();
	}

	template<class Pair, class Iter>
	bool operator!=(const map_iterator<Pair, Iter>& it1, const map_iterator<Pair, Iter>& it2) {
		return it1.base() != it2.base();
	}


	template< class _Key, class _T, class _Compare = std::less<_Key>, class _Alloc = std::allocator<ft::pair<const _Key, _T> > >
	class map {
		public:

			typedef _Key                           key_type;
			typedef _T                             mapped_type;
			typedef ft::pair<const _Key, _T>       value_type;
			typedef _Compare                       key_compare;
			typedef _Alloc                         allocator_type;

			
		private:
			typedef BItree<key_type, value_type, key_compare> _Bi_type;

			_Bi_type _tree;

		public:
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef map_iterator<pointer, typename _Bi_type::iterator> iterator;
			typedef map_iterator<pointer, typename _Bi_type::const_iterator> const_iterator;
			typedef typename _Bi_type::size_type size_type;
			typedef typename _Bi_type::difference_type difference_type;


			map() : _tree() {}

			// Capacity

			bool empty() const {
				return _tree.empty();
			}

			size_type size() const {
				return _tree.size();
			}

			size_type max_size() const {
				return _tree.max_size();
			}

			// Modifiers

			void insert(const value_type& value) {//not void
				_tree.insert(value);
			}

			void erase(iterator position) {
				_tree.erase(position.base());
			}

			size_type erase(const key_type& key) {
				return _tree.erase(key);
			}

			// Iterator

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

			// Lookup

			iterator find(const key_type& key) {
				return iterator(_tree.find(key));
			}

			const_iterator find(const key_type& key) const {
				return const_iterator(_tree.find(key));
			}

			size_type count(const key_type& key) const {
				return _tree.count(key);
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
	};
}

#endif