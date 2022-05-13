#include "../utils/color.hpp"
#include "../utils/Test.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <csignal>
#include <ctime>
#include <chrono>
#include <sys/time.h>

#ifdef STD
	#include <vector>
	namespace ft = std;
	std::ofstream ofs("testOutput/std_vector_out.txt");
#else
	#include "../../vector.hpp" // include your stack header file
	std::ofstream ofs("testOutput/ft_vector_out.txt");

#endif

int nb = 1;

class leakstest {
	public:
		std::string *name;
		leakstest() {
			this->name = new std::string("");
		}
		leakstest(const leakstest& other) {
			*this = other;
		}
		leakstest &operator=(const leakstest &other) {
			if (this != &other) {
				// if (this->name != NULL) {
				// 	delete this->name;
				// }
				if (other.name != NULL && this->name != NULL) {
					*this->name = *other.name;
				}
			}
			return *this;
		}
		leakstest(const std::string &name) {
			this->name = new std::string(name);
		}
		~leakstest() {
			if (this->name != NULL) {
				delete this->name;
				this->name = NULL;
			}
		}
};

void segfault_handler(int sig) {
	Test<std::string>("SEGFAULT", false);
	throw std::runtime_error("SEGFAULT");

}

int main(int ac, char **av, char **env) {

	std::signal(SIGSEGV, &segfault_handler);
	ofs << "VECTOR TEST";
	
	ft::vector<int> v;

	// struct timeval time_now;
	// gettimeofday(&time_now, NULL);
	// time_t time_start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);


	// test 1
	try {
		Test<bool>(v.empty(), false);
	} catch (...) {}
	// test 2
	try {
		Test<size_t>(v.size(), false);
	} catch (...) {}
	// test 3
	try {
		Test<size_t>(v.capacity(), false);
	} catch (...) {}
	// test 4
	v.reserve(10);
	try {
		Test<size_t>(v.capacity(), false);
	} catch (...) {}
	// test 5
	v.push_back(17);
	try {
		Test<size_t>(v.size(), false);
	} catch (...) {}
	// test 6
	try {
		Test<int>(v[0], false );
	} catch (...) {}
	// test 7
	v.resize(7, 4);
	try {
		Test<size_t>(v.size(), false);
	} catch (...) {}
	// test 8
	v.push_back(2);
	try {
		Test<size_t>(v.capacity(), false);
	} catch (...) {}
	// test 9
	v.pop_back();
	try {
		Test<size_t>(v.size(), false);
	} catch (...) {}
	// test 10
	try {
		Test<int>(v[v.size() - 1], false);
	} catch (...) {}
	// test 11
	try {
		Test<int>(*v.begin(), false);
	} catch (...) {}
	// test 12
	try {
		ft::vector<leakstest> vl;
		vl.push_back(leakstest("test"));

	} catch(...) {}

	ofs.close();

	// gettimeofday(&time_now, NULL);
	// time_t time_end = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	// std:: cout << "time: " << time_end - time_start << " ms" << std::endl;


	return 0;
}