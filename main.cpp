#include "vector.hpp"
#include "iterator_traits.hpp"
#include <iostream>
#include <vector>
#include <stack>


int main(void) {
	{
		std::vector<int> v;


		v.reserve(10);
		v.push_back(17);
		v.resize(7, 8);
		v.push_back(2);
		std::vector<int>::iterator it = v.begin();
		std::cout << "it = " << *it << std::endl;
		it++;
		std::cout << "it = " << *it << std::endl;

		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			std::cout << *it << std::endl;
		}
		// v.shrink_to_fit();


		// std::cout << a-> << std::endl;

		// std::cout << "v.size() = " << v.size() << std::endl;
		// std::cout << "v.capacity() = " << v.capacity() << std::endl;
		// std::cout << std::boolalpha << "v.empty() = " << v.empty() << std::endl;
		// for (size_t i = 0; i < v.size(); ++i)
		// 	std::cout << v[i] << std::endl;
	
	}

	std::cout << "---------------------------------------------" << std::endl;

	{
		ft::vector<int> v;
		v.reserve(10);
		v.push_back(17);
		v.resize(7, 8);
		v.push_back(2);
		ft::vector<int>::iterator it = v.begin();
		std::cout << "it = " << *it << std::endl;
		it++;
		std::cout << "it = " << *it << std::endl;
		
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			std::cout << *it << std::endl;
		}

		// std::cout << a-> << std::endl;

		// std::cout << "v.size() = " << v.size() << std::endl;
		// std::cout << "v.capacity() = " << v.capacity() << std::endl;
		// std::cout << std::boolalpha << "v.empty() = " << v.empty() << std::endl;
		// for (size_t i = 0; i < v.size(); ++i)
		// 	std::cout << v[i] << std::endl;

	}
	std::cout << "---------------------------------------------" << std::endl;

	std::stack<int> a;
}