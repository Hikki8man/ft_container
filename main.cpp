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

std::ostream& operator<<(std::ostream& os, const leakstest& l) {
	os << l.name;
	return os;
}

int main(void) {

		std::cout << std::boolalpha << "std int is int: " << std::is_integral<const int>::value << std::endl;
		std::cout << std::boolalpha << "ft int is int: " << ft::is_integral<const int>::value << std::endl;
	{
		std::vector<leakstest> v;

		leakstest a("a");
		leakstest b("b");
		leakstest c("c");
		leakstest d("d");

 
		std::cout << "~~~~~~~~~~" << std::endl;

		v.reserve(3);

		

		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		// std::cout << "v.capacity() = " << v.capacity() << std::endl;
		v.insert(v.begin() + 1, d);
		v.assign(3, leakstest("e"));

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

		v.reserve(3);

		

		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		// std::cout << "v.begin() = " << *v.begin() << std::endl;
		// std::cout << "v.capacity() = " << v.capacity() << std::endl;
		v.insert(v.begin() + 1, d);

		// std::cout << "~~~~~~~~~~" << std::endl;

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