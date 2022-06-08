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
	for (auto it = m.begin(); it != m.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl;
	}

	ft::BItree<int, ft::pair<int, char> > bt;
	bt.insert(ft::make_pair(1, 'a'));
	// std::cout << "bt.begin() = " << << std::endl;

	// std::__tree<int, std::pair<int, char>, _Select1st<std::pair<int, char> >, std::less<int>, std::allocator<std::pair<int, char>> >
	return 0;
}