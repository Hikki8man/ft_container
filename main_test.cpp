#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "map.hpp"
// #include "binary_tree.hpp"
// #include <pair>


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

	}


	std::cout << "--------------------------------" << std::endl;

	std::cout << "--------------------------------" << std::endl;

	{

		ft::map<int, char> m;


		basic_map(m);

		ft::map<int, char>::iterator h = m.find(10);
		// std::cout << h->first << std::endl;
		m.erase(10);
		
		// std::cout << "h: " << h->first << " left: " << h.base()->left->pair.first << " right: " << h.base()->right->pair.first << " par: " << h.base()->parent->pair.first << std::endl;
		// ft::map<int, char>::iterator it = m.end();
		// --it;

		// m.erase(m.begin(),it);

		std::cout << "--------------------------------" << std::endl;


	}



	return 0;
}