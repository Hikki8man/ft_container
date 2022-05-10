#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <fstream>

extern std::ofstream ofs;

template <typename T>
class Test {
	public:
		Test(int n, T a, bool sameTest) {
			if (sameTest == false)
				ofs << "Test " << n << ": " << a << std::endl;
			else
				ofs << " " << a << std::endl;
		}
};

#endif // TEST_HPP