#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "map.hpp"
#include "binary_tree.hpp"
// #include <pair>



int main() {

	{
		std::map<int, char> m;

		// m.insert(std::make_pair(1, 'a'));
		m.insert(std::make_pair(1, 'a'));
		m.insert(std::make_pair(2, 'b'));
		m.insert(std::make_pair(3, 'c'));
		// m.insert(std::make_pair(0, 'd'));
		m.insert(std::make_pair(5, 'e'));
		

		auto it = m.equal_range(1);

		std::cout << "RANGE first: " << it.first->first << " second: " << it.second->first << std::endl;
	}


	std::cout << "--------------------------------" << std::endl;

	std::cout << "--------------------------------" << std::endl;

	{

		ft::map<int, char> m;

		m.insert(ft::make_pair(1, 'a'));
		m.insert(ft::make_pair(2, 'b'));
		m.insert(ft::make_pair(3, 'c'));
		m.insert(ft::make_pair(5, 'd'));

		auto it = m.equal_range(1);

		std::cout << "RANGE first: " << it.first->first << " second: " << it.second->first << std::endl;


	}

	return 0;
}