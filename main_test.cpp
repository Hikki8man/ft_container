#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "map/map.hpp"
#include <stack>
// #include "stack.hpp"
// #include "binary_tree.hpp"
// #include <pair>

template<class _Tp>
	struct sup
	{
		bool operator()(const _Tp& __x, const _Tp& __y) const
      	{ return __x > __y; }
	};
	

void basic_map(ft::map<int, char>& map) {
	try {
		map.insert(ft::make_pair(8, 'a'));
		map.insert(ft::make_pair(10, 'b'));
		map.insert(ft::make_pair(3, 'c'));
		map.insert(ft::make_pair(1, 'd'));
		map.insert(ft::make_pair(6, 'e'));
		map.insert(ft::make_pair(4, 'f'));
		map.insert(ft::make_pair(7, 'g'));
		map.insert(ft::make_pair(14, 'h'));
		map.insert(ft::make_pair(13, 'i'));
	}
	catch(...) {}

	/*
				8
		       / \
	          3   10
			 / \	 \
			1   6	  14
		   	   / \	  /
		      4   7  13
	*/
}


int main() {

	{
		std::map<int, char> m;

		m.insert(std::make_pair(8, 'a'));
		m.insert(std::make_pair(10, 'b'));
		m.insert(std::make_pair(3, 'c'));
		m.insert(std::make_pair(1, 'd'));
		m.insert(std::make_pair(6, 'e'));
		m.insert(std::make_pair(4, 'f'));
		m.insert(std::make_pair(7, 'g'));
		m.insert(std::make_pair(14, 'h'));
		m.insert(std::make_pair(13, 'i'));

		// m.insert(m.end(), std::make_pair(11, 'd'));
		// m.insert(m.find(14), std::make_pair(0, 'd'));
		// m.insert(m.begin(), std::make_pair(15, 'a'));
		// // m.insert(m.end(), std::make_pair(100, 'a'));
		// // m.insert(m.end(), std::make_pair(2, 'a'));
		// for (std::map<int, char>::iterator it = m.begin(); it != m.end(); ++it) {
		// 	std::cout << it->first << " ";
		// }
		std::cout << "lower bound: " << m.lower_bound(11)->first << std::endl;
		// std::cout << std::endl;
		// m.insert(m.find(10), std::make_pair(0, 'd'));
		// m.insert(m.find(3), std::make_pair(13, 'd'));
		// m.insert(m.find(3), std::make_pair(13, 'd'));
		// std::map<int, char>::iterator it = m.find(4);

		// for (std::map<int, char>::iterator it = m.begin(); it != m.end(); ++it) {
		// 	std::cout << it->first << " ";
		// }
		// std::cout << std::endl;
		

	}


	std::cout << "--------------------------------" << std::endl;

	std::cout << "--------------------------------" << std::endl;

	{
		typedef ft::map<int, char>::iterator iterator;
		ft::map<int, char> m;

		iterator it;
		it = m.insert(m.begin(), ft::make_pair(15, 'a'));
		m.clear();
		for (it = m.begin(); it != m.end(); it++) {
			std::cout << it->first << std::endl;
		}


	}



	return 0;
}