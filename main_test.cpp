#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "map.hpp"
// #include "binary_tree.hpp"
// #include <pair>



int main() {

	{
		std::map<int, char> m;

		m.insert(std::make_pair(15, 'a'));
		m.insert(std::make_pair(20, 'b'));
		m.insert(std::make_pair(10, 'c'));
		m.insert(std::make_pair(8, 'd'));
		m.insert(std::make_pair(12, 'e'));

		// m.insert(std::make_pair(18, 'f'));
		m.insert(std::make_pair(25, 'g'));
		m.insert(std::make_pair(16, 'h'));
		


		std::cout << "upper_bound: " << m.upper_bound(9)->first << std::endl;

		std::cout << "lower_bound: " << m.lower_bound(9)->first << std::endl;

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
		// m.insert(ft::make_pair(25, 'g'));
		// m.insert(ft::make_pair(16, 'h'));



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

		ft::rb_tree<int, ft::pair<const int, char>, std::less<int> >::iterator ite = m._tree.begin();

		for (; ite != m._tree.end(); ++ite) {
			std::cout << "first: " << ite->pair.first << " color: " << ite->is_black  << std::endl;
		}

		// ite = m._tree.find(16);

		// std::cout << ite->parent->pair.first << std::endl;



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