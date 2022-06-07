#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "map.hpp"

int main() {

	std::map<int, char> m;

	m.insert(std::make_pair(1, 'a'));
	m.insert(std::make_pair(2, 'b'));
	m.insert(std::make_pair(3, 'c'));
	m.insert(std::make_pair(0, 'd'));
	for (auto it = m.begin(); it != m.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl;
	}
	
	return 0;
}