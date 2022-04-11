#include "vector.hpp"
#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> v(13, 5);
	v.push_back(10);

	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
}