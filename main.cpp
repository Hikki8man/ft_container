#include "vector.hpp"
#include "iterator_traits.hpp"
#include <iostream>
#include <vector>
#include <stack>


class leakstest {
	public:
		std::string *name;
		leakstest() {
			this->name = NULL;
		}
		leakstest(const leakstest& other) {
			*this = other;
		}
		leakstest &operator=(const leakstest &other) {
			this->name = new std::string(*other.name);
			return *this;
		}
		leakstest(const std::string &name) {
			this->name = new std::string(name);
		}
		~leakstest() {
			// std::cout << "leakstest destructor" << std::endl;
			if (this->name != NULL) {
				delete this->name;
			}
		}
};

int main(void) {
	{
		std::vector<int> v;

		for (int i = 0; i < 8; ++i) {
			v.push_back(i);
		}

		std::cout << "v.size() = " << v.size() << std::endl;
		std::cout << "v.capacity() = " << v.capacity() << std::endl;

		v.insert(v.end(), 42);

		std::cout << "v.size() = " << v.size() << std::endl;
		std::cout << "v.capacity() = " << v.capacity() << std::endl;

		for (int i = 0; i < v.size(); ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
		
	
	}

	std::cout << "---------------------------------------------" << std::endl;

	{
		ft::vector<int> v;

		for (int i = 0; i < 11; ++i) {
			v.push_back(i);
		}

		

	}
	std::cout << "---------------------------------------------" << std::endl;

}