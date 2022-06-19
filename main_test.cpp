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

		std::map<int, char>::const_iterator ite2 = m.find(15);

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
		// ite = m._tree.find(16);

		// std::cout << ite->parent->pair.first << std::endl;



		std::cout << "--------------------------------" << std::endl;

		auto tree = m._tree;

		ft::rb_tree<int, ft::pair<const int, char>, std::less<int> >::const_iterator it = tree.begin();

		std::cout << it->pair.first << std::endl;

		// ft::map<int, char>::const_iterator ite2 = m.find(15);


	}



	return 0;
}