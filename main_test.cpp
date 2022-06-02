#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "map.hpp"

int main() {

	std::pair<std::string, int> p("a", 1);
	std::pair<std::string, int> p2("b", 2);

	std::cout << p.first << " " << p.second << std::endl;	
	std::cout << p2.first << " " << p2.second << std::endl;
	
}