#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "map.hpp"
#include "binary_tree.hpp"
// #include <pair>



int main() {

	std::map<int, char> m;

	m.insert(std::make_pair(1, 'a'));
	m.insert(std::make_pair(2, 'b'));
	m.insert(std::make_pair(3, 'c'));
	m.insert(std::make_pair(0, 'd'));
	m.insert(std::make_pair(5, 'e'));
	
	std::map<int, char>::iterator it = m.begin();

	it = m.upper_bound(4);

	std::cout << it->first << std::endl;

	std::cout << "--------------------------------" << std::endl;

	ft::BItree<int, ft::pair<int, char>, std::less<int> > bt;
	bt.insert(ft::make_pair(1, 'a'));
	bt.insert(ft::make_pair(2, 'b'));
	bt.insert(ft::make_pair(3, 'c'));
	bt.insert(ft::make_pair(5, 'e'));

	ft::BItree<int, ft::pair<int, char>, std::less<int> >::iterator it2 = bt.begin();

	for (; it2 != bt.end(); ++it2) {
		std::cout << it2->pair.first << " " << it2->pair.second << std::endl;
	}

	it2 = bt.find(2);

	std::cout << "found: " << it2->pair.first << " " << it2->pair.second << std::endl;

	// bt.erase(bt.begin());

	// std::cout << it2->pair.first << " " << std::endl;

	// std::cout << node->pair.first << " " << node->pair.second << std::endl;
	// std::cout << * << std::endl;

	// std::cout << it2->first << " " << it2->second << " " << it2->second << std::endl;

	// std::__tree<int, std::pair<int, char>, _Select1st<std::pair<int, char> >, std::less<int>, std::allocator<std::pair<int, char>> >
	return 0;
}