#include "../utils/color.hpp"
#include "../utils/Test.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>

#ifdef STD
	#include <vector>
	namespace ft = std;
	std::ofstream ofs("testOutput/std_vector_out.txt");
	std::string exec_name("-atExit -- std_vector");
#else
	#include "../../vector.hpp" // include your stack header file
	std::ofstream ofs("testOutput/ft_vector_out.txt");

#endif

// template <typename T, typename toPrint>
// 	void printVector(ft::vector<T> &v)
// 	{
// 		for (int i = 0; i < v.size(); i++)
// 		{
// 			Test<toPrint>(0, v)
// 		}
// 		std::cout << std::endl;
// 	}
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
			if (this->name != NULL) {
				delete this->name;
			}
		}
};

int main(int ac, char **av, char **env) {

	ofs << "VECTOR TEST" << std::endl;
	ft::vector<int> v;

	// // test 1
	// Test<bool>(1, v.empty(), false);
	// // test 2
	// Test<size_t>(2, v.size(), false);
	// // test 3
	// Test<size_t>(3, v.capacity(), false);
	// // test 4
	// v.reserve(10);
	// Test<size_t>(4, v.capacity(), false);
	// // test 5
	// v.push_back(17);
	// Test<size_t>(5, v.size(), false);
	// // test 6
	// Test<int>(6, v[0], false );
	// // test 7
	// v.resize(7, 4);
	// Test<size_t>(7, v.size(), false);
	// // test 8
	// v.push_back(2);
	// Test<size_t>(8, v.capacity(), false);
	// // test 9
	// v.pop_back();
	// Test<size_t>(9, v.size(), false);
	// // test 10
	// Test<int>(10, v[v.size() - 1], false);
	// Test 11
	ft::vector<leakstest> v2;
	// for (int i = 0; i < 10; ++i) {
	// 	leakstest l("test");
	// 	v2.push_back(leakstest(l));
	// }
	// v2.pop_back();
	// Test<std::string>(11, "Print tab", false);
	// for (int i = 0; i < v2.size(); ++i) {
	// 	Test<std::string>(11, *v2[i].name, true);
	// }
	// test 12
	Test<std::string>(12, "Print tab", false);
	// v2.reserve(30);
	std::cout << "capacity: " << v2.capacity() << std::endl;
	v2.resize(20);
	for (int i = 0; i < v2.size(); ++i) {
		if (v2[i].name != NULL) {
			Test<std::string>(11, *v2[i].name, true);
		}
		else
			Test<std::string>(11, "NULL", true);
	}
	// test 13
	Test<std::string>(13, "Print tab", false);
	v2.resize(2);
	for (int i = 0; i < v2.size(); ++i) {
		if (v2[i].name != NULL) {
			Test<std::string>(11, *v2[i].name, true);
		}
		else
			Test<std::string>(11, "NULL", true);
	}
	// test 13
	v2.clear();
	Test<bool>(13, v2.empty(), false);
	// test 14
	Test<size_t>(14, v2.size(), false);
	// test 15
	Test<size_t>(15, v2.capacity(), false);
	// test 16

	ofs.close();

	return 0;
}