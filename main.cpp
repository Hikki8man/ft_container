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


		// for (int i = 0; i < 10; ++i)
		// 	v.push_back(int(i));
		// v.pop_back();
		//test leaks with assign

		std::vector<leakstest> v2;
		// for (int i = 0; i < 10; ++i) {
		// 	leakstest l("test");
		// 	v2.push_back(leakstest(l));
		// }

		size_t size = sizeof(v2);
		std::cout << "size of: " << size << std::endl;
		// v2.pop_back();



		// v.assign(5, leakstest());

		// v.assign(v2.begin() + 1, v2.end()); //throw error if v2 is empty

		// for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		// 	std::cout << *it << std::endl;
		// }
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
		// ft::vector<int> v;
		// for (int i = 0; i < 10; ++i)
		// 	v.push_back(i);
		// v.pop_back();

		ft::vector<leakstest> v2;
		for (int i = 0; i < 10; ++i) {
			leakstest l("test");
			v2.push_back(leakstest(l));
		}
		size_t size = sizeof(v2);
		std::cout << "size of: " << size << std::endl;

		v2.pop_back();


		// v2.pop_back();
		
		// for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		// 	std::cout << *it << std::endl;
		// }

		// std::cout << a-> << std::endl;

		// std::cout << "v.size() = " << v.size() << std::endl;
		// std::cout << "v.capacity() = " << v.capacity() << std::endl;
		// std::cout << std::boolalpha << "v.empty() = " << v.empty() << std::endl;
		// for (size_t i = 0; i < v.size(); ++i)
		// 	std::cout << v[i] << std::endl;

	}
	std::cout << "---------------------------------------------" << std::endl;

}