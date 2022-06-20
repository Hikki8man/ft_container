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

		// std::map<int, char>::const_iterator ite2 = m.begin();
		// for (; ite2 != m.end(); ++ite2) {
		// 	std::cout << ite2->first << " " << ite2->second << std::endl;
		// }
		for (std::map<int, char>::iterator ite = m.begin(); ite != m.end(); ++ite) {
			m.erase(ite);
		}
		for (std::map<int, char>::iterator ite = m.begin(); ite != m.end(); ++ite) {
			std::cout << ite->first << " " << ite->second << std::endl;
		}
		std::cout << std::boolalpha << m.empty() << std::endl;

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
		m.insert(ft::make_pair(25, 'g'));
		m.insert(ft::make_pair(16, 'h'));



		// std::cout << "size: " << m.size() << std::endl;
		// ite = m._tree.find(16);

		// std::cout << ite->parent->pair.first << std::endl;
		// for (auto ite = m.begin(); ite != m.end(); ++ite) {
		// 	std::cout << ite->first << " " << ite->second << std::endl;
		// }

		// ft::map<int, char>::const_iterator ite2 = m.begin();
		// ft::map<int, char>::const_iterator ite3 = m.end();

		// for (; ite2 != ite3; ++ite2) {
		// 	std::cout << ite2->first << " " << ite2->second << std::endl;
		// }

		for (ft::map<int, char>::iterator ite = m.begin(); ite != m.end(); ++ite) {
			m.erase(ite);
		}
		std::cout << std::boolalpha << m.empty() << std::endl;
		std::cout << "size: " << m.size() << std::endl;
		for (ft::map<int, char>::iterator ite = m.begin(); ite != m.end(); ++ite) {
			std::cout << ite->first << " " << ite->second << std::endl;
		}


		


		std::cout << "--------------------------------" << std::endl;

		//  const ft::rb_tree<int, ft::pair<const int, char>, std::less<int> > tree(m._tree);

		// ft::rb_tree<int, ft::pair<const int, char>, std::less<int> >::const_iterator it = tree.begin();

		// std::cout << it->pair.first << std::endl;

		// ft::map<int, char>::const_iterator ite2 = m.find(15);


	}



	return 0;
}