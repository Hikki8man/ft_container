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

		m.insert(std::make_pair(15, 'a'));
		m.insert(std::make_pair(20, 'b'));
		m.insert(std::make_pair(10, 'c'));
		m.insert(std::make_pair(8, 'd'));
		m.insert(std::make_pair(12, 'e'));

		m.insert(std::make_pair(18, 'f'));
		m.insert(std::make_pair(30, 'g'));
		m.insert(std::make_pair(16, 'h'));
		m.insert(std::make_pair(19, 'i'));

		m.erase(20);


		std::cout << "size: " << m.size() << std::endl;
		
		for (auto it = m.begin(); it != m.end(); ++it) {
			std::cout << "first: " << it->first << " second: " << it->second << std::endl;
		}

	}


	std::cout << "--------------------------------" << std::endl;

	std::cout << "--------------------------------" << std::endl;

	{

		ft::map<int, char> m;

		m.insert(ft::make_pair(15, 'a'));
		m.insert(ft::make_pair(20, 'b'));
		m.insert(ft::make_pair(10, 'c'));
		m.insert(ft::make_pair(8, 'd'));
		m.insert(ft::make_pair(12, 'e'));

		m.insert(ft::make_pair(18, 'f'));
		m.insert(ft::make_pair(30, 'g'));
		m.insert(ft::make_pair(16, 'h'));
		m.insert(ft::make_pair(19, 'i'));

		m.erase(20);

		std::cout << "size: " << m.size() << std::endl;

		for (auto it = m.begin(); it != m.end(); ++it) {
			std::cout << "first: " << it->first << " second: " << it->second << std::endl;
		}


	}

	// std::cout << "--------------------------------" << std::endl;

	return 0;
}