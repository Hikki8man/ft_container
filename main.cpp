#include "vector.hpp"
#include "iterator_traits.hpp"
#include <iostream>
#include <vector>
#include <stack>


int main(void) {
	{
		std::vector<int *> v;


		for (int i = 0; i < 10; ++i)
			v.push_back(new int(i));
		v.pop_back();
		//test leaks with assign

		std::vector<int> v2;


		// v2.assign(10, 33);

		// v.assign(v2.begin() + 1, v2.end()); //throw error if v2 is empty

		for (std::vector<int *>::iterator it = v.begin(); it != v.end(); it++) {
			std::cout << **it << std::endl;
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
		for (int i = 0; i < 10; ++i)
			v.push_back(i);
		v.pop_back();
		
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