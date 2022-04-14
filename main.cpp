#include "vector.hpp"
#include <iostream>
#include <vector>

int main(void) {
	{
		std::vector<int> v;
		std::cout << std::boolalpha << "v.empty() = " << v.empty() << std::endl;
		// try {
		// 	v.resize(4611686018427387903);
		// }
		// catch (std::exception & e) {
		// 	std::cout << e.what() << std::endl;
		// }
		v.resize(5);
		// v.reserve(3);
		// v.push_back(1);
		// v.reserve(5);
		// v.push_back(2);
		// v.push_back(3);
		// v.push_back(4);
		// v.push_back(5);
		// v.resize(9, 17);
		v.resize(7);
		// std::cout << "out of bouds = " << v[4] << std::endl;
		std::cout << "v.size() = " << v.size() << std::endl;
		std::cout << "v.capacity() = " << v.capacity() << std::endl;
		std::cout << std::boolalpha << "v.empty() = " << v.empty() << std::endl;
		for (size_t i = 0; i < v.size(); ++i)
			std::cout << v[i] << std::endl;
	}

	std::cout << "---------------------------------------------" << std::endl;

	{
		vector<int> v;
		std::cout << std::boolalpha << "v.empty() = " << v.empty() << std::endl;
		// try {
		// 	v.resize(4611686018427387903);
		// }
		// catch (std::exception & e) {
		// 	std::cout << e.what() << std::endl;
		// }
		v.resize(5);
		// v.reserve(3);
		// v.push_back(1);
		// v.reserve(5);
		// // v.push_back(2);
		// // v.push_back(3);
		// // v.push_back(4);
		// // v.push_back(5);
		// v.resize(9, 17);
		v.resize(7);
		std::cout << "v.size() = " << v.size() << std::endl;
		std::cout << "v.capacity() = " << v.capacity() << std::endl;
		std::cout << std::boolalpha << "v.empty() = " << v.empty() << std::endl;
		for (size_t i = 0; i < v.size(); ++i)
			std::cout << v[i] << std::endl;
	}
}