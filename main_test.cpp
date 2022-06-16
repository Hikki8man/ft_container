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

		std::map<int, char> m2;

		m2.insert(std::make_pair(1, 'a'));
		m2.insert(std::make_pair(2, 'b'));
		m2.insert(std::make_pair(33, 'c'));
		m2.insert(std::make_pair(4, 'd'));

		m.insert(std::make_pair(15, 'a'));
		m.insert(std::make_pair(20, 'b'));
		m.insert(std::make_pair(10, 'c'));
		m.insert(std::make_pair(8, 'd'));
		m.insert(std::make_pair(12, 'e'));

		// m.insert(std::make_pair(18, 'f'));
		m.insert(std::make_pair(25, 'g'));
		m.insert(std::make_pair(16, 'h'));
		


		m.insert(m2.begin(), m2.end());


		std::cout << "size: " << m.size() << std::endl;
		
		for (auto it = m.begin(); it != m.end(); ++it) {
			std::cout << "first: " << it->first << " second: " << it->second << std::endl;
		}

	}


	std::cout << "--------------------------------" << std::endl;

	std::cout << "--------------------------------" << std::endl;

	{

		ft::map<int, char> m;

		ft::map<int, char> m2;

		m2.insert(ft::make_pair(1, 'a'));
		m2.insert(ft::make_pair(2, 'b'));
		m2.insert(ft::make_pair(33, 'c'));
		m2.insert(ft::make_pair(4, 'd'));


		m.insert(ft::make_pair(15, 'a'));
		m.insert(ft::make_pair(20, 'b'));
		m.insert(ft::make_pair(10, 'c'));
		m.insert(ft::make_pair(8, 'd'));
		m.insert(ft::make_pair(12, 'e'));

		// m.insert(ft::make_pair(18, 'f'));
		m.insert(ft::make_pair(25, 'g'));
		m.insert(ft::make_pair(16, 'h'));


		m.insert(m2.begin(), m2.end());


		std::cout << "size: " << m.size() << std::endl;

		// auto ite = m.end();

		// --ite;
		// ++ite;
		// ++ite;
		// ++ite;

		// std::cout << "first: " << ite->first << " second: " << ite->second << std::endl;

		for (auto it = m.begin(); it != m.end(); ++it) {
			std::cout << "first: " << it->first << " second: " << it->second << std::endl;
		}


		std::cout << "--------------------------------" << std::endl;

		// ft::map<int, char> m2(m);

		// std::cout << "size: " << m2.size() << std::endl;
		// std::cout << "root key: " << m._tree._root->pair.first << std::endl;

		// for (auto it = m2.begin(); it != m2.end(); ++it) {
		// 	std::cout << "first: " << it->first << " second: " << it->second << std::endl;
		// }


	}



	return 0;
}