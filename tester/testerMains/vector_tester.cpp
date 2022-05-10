
#include "../utils/color.hpp"
#include "../utils/Test.hpp"
#include <fstream>

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

	// test 1
	Test<bool>(1, v.empty(), false);
	// test 2
	Test<size_t>(2, v.size(), false);
	// test 3
	Test<size_t>(3, v.capacity(), false);
	// test 4
	v.reserve(10);
	Test<size_t>(4, v.capacity(), false);
	// test 5
	v.push_back(17);
	Test<size_t>(5, v.size(), false);
	// test 6
	Test<int>(6, v[0], false );
	// test 7
	v.resize(7, 4);
	Test<size_t>(7, v.size(), false);
	// test 8
	v.push_back(2);
	Test<size_t>(8, v.capacity(), false);
	// test 9
	v.pop_back();
	Test<size_t>(9, v.size(), false);
	// test 10
	Test<int>(10, v[v.size() - 1], false);
	// Test leaks
	ft::vector<leakstest> v2;
	for (int i = 0; i < 10; ++i) {
		leakstest l("test");
		v2.push_back(leakstest(l));
	}
	v2.pop_back();
	ofs.close();

	return 0;
}