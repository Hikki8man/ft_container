#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <fstream>

#ifdef STD
	#include <stack>
	namespace ft = std;
	std::ofstream ofs("testOutput/std_stack_out.txt");
#else
	#include "../../stack.hpp" // include your stack header file
	std::ofstream ofs("testOutput/ft_stack_out.txt");

#endif


#include "../utils/color.hpp"
#include "../utils/Test.hpp"

int main (void) {

	{
		ofs << "STACK TEST" << std::endl;
		ft::stack<int> a;

		// Test 1
		Test<bool>(1, a.empty(), false);
		// Test 2
		a.push(1);
		Test<bool>(2, a.empty(), false);
		// Test 3
		Test<int>(3, a.top(), false);
		// Test 4
		a.pop();
		Test<bool>(4, a.empty(), false);
		// Test 5
		for (int i = 0; i < 10; ++i) {
			a.push(i);
		}
		Test<size_t>(5, a.size(), false);
		// Test 6
		Test<int>(6, a.top(), false);
		// Test 7
		ft::stack<int> c;
		for (int i = 0; i < 20; ++i) {
			c.push(i + 20);
		}
		a = c;
		Test<size_t>(7, a.size(), false);
		// Test 8
		Test<int>(8, a.top(), false);
		// Test 9
		c.pop();
		Test<bool>(9, a.top() < c.top(), false);
		// Test 10
		Test<bool>(10, a.top() > c.top(), false);
		// Test 11
		Test<bool>(11, a.top() == c.top(), false);
		// Test 12
		Test<bool>(12, a.top() != c.top(),false);
		// Test 13
		Test<bool>(13, a.top() <= c.top(), false);
		// Test 14
		Test<bool>(14, a.top() >= c.top(), false);
	}
	{
		ft::stack <std::string, std::list<std::string> > a;

		// Test 15
		Test<bool>(15, a.empty(), false);
		// Test 16
		a.push("1");
		Test<bool>(16, a.empty(), false);
		// Test 17
		Test<std::string>(17, a.top(), false);
		// Test 18
		a.pop();
		Test<bool>(18, a.empty(), false);
		// Test 19
		for (int i = 0; i < 10; ++i) {
			a.push("string " + std::to_string(i + 1));
		}
		Test<size_t>(19, a.size(), false);
		// Test 20
		Test<std::string>(20, a.top(), false);
		// Test 21
		ft::stack<std::string, std::list<std::string> > c;
		for (int i = 0; i < 20; ++i) {
			c.push("string " + std::to_string(i + 1));
		}
		a = c;
		Test<size_t>(21, a.size(), false);
		// Test 22
		Test<std::string>(22, a.top(), false);
		// Test 23
		c.pop();
		Test<bool>(23, a.top() < c.top(), false);
		// Test 24
		Test<bool>(24, a.top() > c.top(), false);
		// Test 25
		Test<bool>(25, a.top() == c.top(), false);
		// Test 26
		Test<bool>(26, a.top() != c.top(), false);
		// Test 27
		Test<bool>(27, a.top() <= c.top(), false);
		// Test 28
		Test<bool>(28, a.top() >= c.top(), false);
	}
	ofs.close();
}