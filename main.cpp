#include "vector.hpp"
#include <iostream>
#include <vector>

int main(void) {
	{
		std::vector<int> v;
		v.reserve(10);
		v.resize(7, 8);
		v.push_back(2);
		v.shrink_to_fit();
		std::cout << "v.size() = " << v.size() << std::endl;
		std::cout << "v.capacity() = " << v.capacity() << std::endl;
		std::cout << std::boolalpha << "v.empty() = " << v.empty() << std::endl;
		for (size_t i = 0; i < v.size(); ++i)
			std::cout << v[i] << std::endl;
	}

	std::cout << "---------------------------------------------" << std::endl;

	{
		vector<int> v;
		v.reserve(10);
		v.resize(7, 8);
		v.push_back(2);
		v.shrink_to_fit();
		std::cout << "v.size() = " << v.size() << std::endl;
		std::cout << "v.capacity() = " << v.capacity() << std::endl;
		std::cout << std::boolalpha << "v.empty() = " << v.empty() << std::endl;
		for (size_t i = 0; i < v.size(); ++i)
			std::cout << v[i] << std::endl;
	}
}