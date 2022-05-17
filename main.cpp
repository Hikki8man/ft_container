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
		std::vector<leakstest> v;

		leakstest a("a");
		leakstest b("b");
		leakstest c("c");
		leakstest d("d");

 
		std::cout << "~~~~~~~~~~" << std::endl;

		v.reserve(8);

		

		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		// std::cout << "v.capacity() = " << v.capacity() << std::endl;
		v.insert(v.begin(), d);

		std::cout << "~~~~~~~~~~" << std::endl;
	
	}

	{
		// std::vector<int> v;

		// for (int i = 0; i < 10; i++) {
		// 	v.push_back(i);
		// }

		// v.insert(v.end(), 100);

		// for (int i = 0; i < v.size(); i++) {
		// 	std::cout << v[i] << " ";
		// }
		// std::cout << std::endl;

		// for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
		// 	std::cout << *it << std::endl;
		// }
	}

	std::cout << "---------------------------------------------" << std::endl;

	{
		ft::vector<leakstest> v;

		leakstest a("a");
		leakstest b("b");
		leakstest c("c");
		leakstest d("d");

 
		std::cout << "~~~~~~~~~~" << std::endl;

		v.reserve(8);

		

		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		// std::cout << "v.capacity() = " << v.capacity() << std::endl;
		v.insert(v.begin(), d);

		std::cout << "~~~~~~~~~~" << std::endl;

	}

	{
		// ft::vector<int> v;

		// for (int i = 0; i < 10; i++) {
		// 	v.push_back(i);
		// }

		// v.insert(v.end(), 100);

		// for (int i = 0; i < v.size(); i++) {
		// 	std::cout << v[i] << " ";
		// }
		// std::cout << std::endl;
		// for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
		// 	std::cout << *it << std::endl;
		// }
	}
	std::cout << "---------------------------------------------" << std::endl;

}