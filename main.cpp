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
			// std::cout << "copy constructor of " << name << std::endl;
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


	{
		// std::vector<leakstest> v;

		// leakstest a("a");
		// leakstest b("b");
		// leakstest c("c");
		// leakstest d("d");
		// leakstest e("e");
		// leakstest f("f");
		// leakstest g("g");
		// leakstest h("h");

		// // leakstest a2("a2");
		// // leakstest b2("b2");
		// // leakstest c2("c2");
		// // leakstest d2("d2");
		// // leakstest e2("e2");
		// // leakstest f2("f2");

		// std::vector<leakstest> v2;
		
 
		// std::cout << "~~~~~~~~~~" << std::endl;

		// v.reserve(100);

		// v.push_back(a);
		// v.push_back(b);
		// v.push_back(c);
		// v.push_back(d);
		// v.push_back(e);

		// v2.push_back(f);
		// v2.push_back(g);
		// v2.push_back(h);
		// // v.push_back(f);
		// // v.push_back(g);
		// // v.push_back(h);
		

		// std::cout << "~~~~~~~~~~" << std::endl;

		// v.insert(v.begin() + 1, 1, f);
		// for (auto it = v.begin(); it != v.end(); ++it) {
		// 	std::cout << *it;
		// }
		// std::cout << std::endl;
		// v.insert(v.end(), v2.begin() + 1, v2.end());
		// for (auto it = v.begin(); it != v.end(); ++it) {
		// 	std::cout << *it;
		// }
		// std::cout << std::endl;
		// v.insert(v.begin(), v2.begin(), v2.end());
		// for (auto it = v.begin(); it != v.end(); ++it) {
		// 	std::cout << *it;
		// }
		// std::cout << std::endl;
		// v.insert(v.begin() + 5, v2.begin() + 1, v2.end());
		// // v.insert(v.begin() + 5, v2.begin() + 1, v2.end());

		// std::cout << "capacity: " << v.capacity() << std::endl;
		// for (auto it = v.begin(); it != v.end(); ++it) {
		// 	std::cout << *it;
		// }
		// std::cout << std::endl;

		// std::cout << "~~~~~~~~~~" << std::endl;
	
	}

	{
		std::vector<leakstest> v;
		std::vector<leakstest> v2;
		std::vector<leakstest>::reverse_iterator it;
		v.swap(v2);
		v.reserve(100);
		leakstest a("a");
		leakstest b("b");
		leakstest c("c");
		leakstest d("d");
		leakstest e("e");
		leakstest f("f");
		leakstest g("g");
		leakstest h("h");
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);
		v.push_back(e);

		std::cout << "~~~~~~~~~~" << std::endl;
		v.erase(v.begin());
		std::cout << "~~~~~~~~~~" << std::endl;
		for (int i = 0; i < v.size(); i++) {
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "---------------------------------------------" << std::endl;

	{
		// ft::vector<leakstest> v;

		// leakstest a("a");
		// leakstest b("b");
		// leakstest c("c");
		// leakstest d("d");
		// leakstest e("e");
		// leakstest f("f");
		// leakstest g("g");
		// leakstest h("h");

		// // leakstest a2("a2");
		// // leakstest b2("b2");
		// // leakstest c2("c2");
		// // leakstest d2("d2");
		// // leakstest e2("e2");
		// // leakstest f2("f2");

		// ft::vector<leakstest> v2;
		
 
		// std::cout << "~~~~~~~~~~" << std::endl;

		// v.reserve(100);

		// v.push_back(a);
		// v.push_back(b);
		// v.push_back(c);
		// v.push_back(d);
		// v.push_back(e);

		// v2.push_back(f);
		// v2.push_back(g);
		// v2.push_back(h);
		// // v.push_back(f);
		// // v.push_back(g);
		// // v.push_back(h);
		

		// std::cout << "~~~~~~~~~~" << std::endl;

		// v.insert(v.begin() + 1, 1, f);
		// for (auto it = v.begin(); it != v.end(); ++it) {
		// 	std::cout << *it;
		// }
		// std::cout << std::endl;
		// v.insert(v.end(), v2.begin() + 1, v2.end());
		// for (auto it = v.begin(); it != v.end(); ++it) {
		// 	std::cout << *it;
		// }
		// std::cout << std::endl;
		// v.insert(v.begin(), v2.begin(), v2.end());
		// for (auto it = v.begin(); it != v.end(); ++it) {
		// 	std::cout << *it;
		// }
		// std::cout << std::endl;
		// v.insert(v.begin() + 5, v2.begin() + 1, v2.end());
		// // v.insert(v.begin() + 5, v2.begin() + 1, v2.end());

		// std::cout << "capacity: " << v.capacity() << std::endl;
		// for (auto it = v.begin(); it != v.end(); ++it) {
		// 	std::cout << *it;
		// }
		// std::cout << std::endl;

		// std::cout << "~~~~~~~~~~" << std::endl;

	}

	{
		ft::vector<leakstest> v;

		v.reserve(100);
		leakstest a("a");
		leakstest b("b");
		leakstest c("c");
		leakstest d("d");
		leakstest e("e");
		leakstest f("f");
		leakstest g("g");
		leakstest h("h");
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);
		v.push_back(e);

		for (ft::vector<leakstest>::const_iterator it)
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;

	return 0;

}