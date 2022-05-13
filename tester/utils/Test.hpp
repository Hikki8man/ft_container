#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <fstream>

extern std::ofstream ofs;
extern int nb;

template <typename T>
class Test {
	public:
		Test(T a, bool sameTest) {
			ofs << std::endl;
			if (sameTest == false)
				ofs << "Test " << nb << ": " << a;
			else
				ofs << " " << a;
			nb++;
		}
};

#endif // TEST_HPP