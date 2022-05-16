#include "vector.hpp"
#include "iterator_traits.hpp"
#include <iostream>
#include <vector>
#include <stack>


class leakstest {
	public:
		std::string name;
		leakstest() {
			std::cout << "constructor" << std::endl;
		}
		leakstest(const std::string& name) : name(name) {
			std::cout << "constructor" << std::endl;
		}
		leakstest(const leakstest& other) {
			this->name = other.name;
			std::cout << "copy constructor of " << name << std::endl;
		}
		leakstest &operator=(const leakstest &other) {
			this->name = other.name;
			std::cout << "assignment of " << name << std::endl;
			return *this;
		}
		// leakstest(const std::string &name) {
		// 	this->name = new std::string(name);
		// }
		~leakstest() {
			std::cout << "leakstest destructor of " << name << std::endl;
		}
};

int main(void) {
	{
		// std::vector<leakstest> v;

		// leakstest a("a");
		// leakstest a1("b");
		// leakstest a2("c");
		// leakstest a3("d");

 
		// std::cout << "~~~~~~~~~~" << std::endl;

		// v.reserve(8);

		// v.push_back(a);
		// v.push_back(a1);
		// v.push_back(a2);
		// std::cout << "v.capacity() = " << v.capacity() << std::endl;

		// v.insert(v.begin(), a3);
	
	}

	{
		std::vector<int> v;

		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
			std::cout << *it << std::endl;
		}
	}

	std::cout << "---------------------------------------------" << std::endl;

	{
		// ft::vector<leakstest> v;

		// leakstest a;
		// leakstest a1;
		// leakstest a2;
		// leakstest a3;
 
		// std::cout << "~~~~~~~~~~" << std::endl;

		// v.push_back(a);
		// v.push_back(a1);
		// v.push_back(a2);
		// std::cout << "v.capacity() = " << v.capacity() << std::endl;
		// v.push_back(a3);	

	}

	{
		ft::vector<int> v;

		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
			std::cout << *it << std::endl;
		}
	}
	std::cout << "---------------------------------------------" << std::endl;

}