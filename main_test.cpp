#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "map.hpp"
#include "binary_tree.hpp"
// #include <pair>



int main() {

	std::map<int, char> m;

	// m.insert(std::make_pair(1, 'a'));
	m.insert(std::make_pair(1, 'a'));
	m.insert(std::make_pair(2, 'b'));
	m.insert(std::make_pair(3, 'c'));
	// m.insert(std::make_pair(0, 'd'));
	m.insert(std::make_pair(5, 'e'));
	
	std::map<int, char>::iterator it = m.begin();


	std::cout << "count: " << m.count(4) << std::endl;

	std::cout << "--------------------------------" << std::endl;

	ft::BItree<int, ft::pair<int, char>, std::less<int> > bt;
	bt.insert(ft::make_pair(1, 'a'));
	bt.insert(ft::make_pair(2, 'b'));
	bt.insert(ft::make_pair(3, 'c'));
	// m.insert(std::make_pair(0, 'd'));
	bt.insert(ft::make_pair(5, 'e'));

	ft::BItree<int, ft::pair<int, char>, std::less<int> >::iterator it2 = bt.begin();

	for (; it2 != bt.end(); ++it2) {
		std::cout << it2->pair.first << " " << it2->pair.second << std::endl;
	}

	// it2 = bt.find(2);

	std::cout << "count: " << bt.count(4) << std::endl;

	std::cout << "--------------------------------" << std::endl;

	ft::map<int, char> m2;

	m2.insert(ft::make_pair(1, 'a'));
	m2.insert(ft::make_pair(2, 'b'));
	m2.insert(ft::make_pair(3, 'c'));
	m2.insert(ft::make_pair(0, 'd'));

	ft::map<int, char>::iterator it3 = m2.begin();

	// std::cout << "it: " << it3->first << " " << it3->second << std::endl;

	for (; it3 != m2.end(); ++it3) {
		std::cout << it3->first << " " << it3->second << std::endl;
	}

	return 0;
}