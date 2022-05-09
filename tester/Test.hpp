#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include "color.hpp"

using namespace std;

template <typename T>
class Test {
	public:
		Test(const string &file_to_test) {
			cmd = "leaks -q " + file_to_test + " >> leaks_" + file_to_test + ".txt";
		}
		Test(int nb, T a, T b) {
			if (a == b)
				cout << FG_GREEN << nb << ": OK | ";
			else
				cout << FG_RED << nb << ": FAIL | ";
		}

		void leaks() {
			cout << cmd.c_str() << endl;
			int leaks = system(cmd.c_str());
			cout << FG_LBLUE << "TESTING LEAKS: " << endl;
			if (leaks == 0)
				cout << FG_GREEN << "No leaks" << RESET_ALL << endl;
			else
				cout << FG_RED << "Leaks detected !" << RESET_ALL << endl;

		}
	private:
		string cmd;
};

#endif // TEST_HPP