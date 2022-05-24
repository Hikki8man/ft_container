#include "vector.hpp"
#include "iterator_traits.hpp"
#include <iostream>
#include <vector>
#include <stack>


class leakstest {
	public:
		std::string name;
		leakstest() {
			// std::cout << "constructor" << std::endl;
		}
		leakstest(const std::string& name) : name(name) {
			// std::cout << "constructor" << std::endl;
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
		~leakstest() {
			std::cout << "leakstest destructor of " << name << std::endl;
		}
};

std::ostream& operator<<(std::ostream& os, const leakstest& l) {
	os << l.name;
	return os;
}

int main(void) {

	std::vector<leakstest> v;

	{
		std::vector<leakstest> v;

		leakstest a("a");
		leakstest b("b");
		leakstest c("c");
		leakstest d("d");
		leakstest e("e");
		// leakstest f("f");
		// leakstest g("g");
		// leakstest h("h");

		// leakstest a2("a2");
		// leakstest b2("b2");
		// leakstest c2("c2");
		// leakstest d2("d2");
		// leakstest e2("e2");
		// leakstest f2("f2");


 
		std::cout << "~~~~~~~~~~" << std::endl;

		v.reserve(20);

		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);
		v.push_back(e);
		// v.push_back(f);
		// v.push_back(g);
		// v.push_back(h);
		

		std::cout << "~~~~~~~~~~" << std::endl;

		v.erase(v.begin(), v.end());
		for (auto it = v.begin(); it != v.end(); ++it) {
			std::cout << *it << std::endl;
		}

		std::cout << "~~~~~~~~~~" << std::endl;
	
	}

	{
	}

	std::cout << "---------------------------------------------" << std::endl;

	{
		ft::vector<leakstest> v;

		leakstest a("a");
		leakstest b("b");
		leakstest c("c");
		leakstest d("d");
		leakstest e("e");
		// leakstest f("f");
		// leakstest g("g");
		// leakstest h("h");

		// leakstest a2("a2");
		// leakstest b2("b2");
		// leakstest c2("c2");
		// leakstest d2("d2");
		// leakstest e2("e2");
		// leakstest f2("f2");


		
 
		std::cout << "~~~~~~~~~~" << std::endl;

		v.reserve(20);

		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);
		v.push_back(e);
		// v.push_back(f);
		// v.push_back(g);
		// v.push_back(h);
		

		std::cout << "~~~~~~~~~~" << std::endl;

		v.erase(v.begin(), v.end());
		for (auto it = v.begin(); it != v.end(); ++it) {
			std::cout << *it << std::endl;
		}

		std::cout << "~~~~~~~~~~" << std::endl;

	}

	{
		// ft::vector<int> v;

		// for (int i = 0; i < 5; i++) {
		// 	v.push_back(i);
		// }

		// std::cout << "~~~~~~~~~~" << std::endl;
		// // v.erase(1);

		// for (int i = 0; i < v.size(); i++) {
		// 	std::cout << v[i] << " ";
		// }
		// std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;

	{
		std::vector<int> v;

		for (int i = 0; i < 5; i++) {
			v.push_back(i);
		}
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			std::cout << *it << " ";
		}
	}

	return 0;

}