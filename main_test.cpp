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

		std::cout << m.find(8)->second << std::endl;

		m.insert(std::make_pair(8, 'b'));

		std::cout << m.find(8)->second << std::endl;

	}


	std::cout << "--------------------------------" << std::endl;

	std::cout << "--------------------------------" << std::endl;

	{
		typedef ft::map<int, char>::iterator iterator;
		ft::map<int, char> m;

		basic_map(m);

		m.insert(ft::make_pair(8, 'a'));

		m.insert(ft::make_pair(8, 'b'));

		m.insert(m.find(8),ft::make_pair(1, 'c'));
		m.insert(m.find(8),ft::make_pair(3, 'c'));
		m.insert(m.find(8),ft::make_pair(4, 'c'));
		m.insert(m.find(8),ft::make_pair(6, 'c'));
		m.insert(m.find(8),ft::make_pair(7, 'c'));
		m.insert(m.find(8),ft::make_pair(10, 'c'));
		m.insert(m.find(8),ft::make_pair(14, 'c'));
		m.insert(m.find(8),ft::make_pair(13, 'c'));
		m.insert(m.find(8),ft::make_pair(8, 'c'));

		for (iterator it = m.begin(); it != m.end(); ++it)
			std::cout << it->first << " " << it->second << std::endl;

	}



	return 0;
}