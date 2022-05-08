#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include "color.hpp"

using namespace std;

template <typename T>
class Test {
	public:
		Test(int nb, T a, T b) {
			if (a == b)
				cout << FG_GREEN << nb << ": OK | ";
			else
				cout << FG_RED << nb << ": FAIL | ";
			++nb;
		}
	static int nb;
};

#endif // TEST_HPP