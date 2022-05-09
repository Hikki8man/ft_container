#include <iostream>
#include <string>

#include "../stack.hpp" // include your stack header file

#include <stack>
#include <vector>
#include <deque>
#include <list>

#include "color.hpp"
#include "Test.hpp"

using namespace std;

int main (void) {
	stack<int> a;
	ft::stack<int> b;


	cout << FG_YELLOW << "STACK TEST:" << endl;

	{

		// Test 1
		Test<bool>(1, a.empty(), b.empty());
		// Test 2
		a.push(1); b.push(1);
		Test<bool>(2, a.empty(), b.empty());
		// Test 3
		Test<int>(3, a.top(), b.top());
		// Test 4
		a.pop(); b.pop();
		Test<bool>(4, a.empty(), b.empty());
		// Test 5
		for (int i = 0; i < 10; ++i) {
			a.push(i); b.push(i);
		}
		Test<size_t>(5, a.size(), b.size());
		// Test 6
		Test<int>(6, a.top(), b.top());
		// Test 7
		stack<int> c;
		ft::stack<int> d;
		for (int i = 0; i < 20; ++i) {
			c.push(i + 20);
			d.push(i + 20);
		}
		a = c;
		b = d;
		Test<size_t>(7, a.size(), b.size());
		// Test 8
		Test<int>(8, a.top(), b.top());
		// Test 9
		c.pop(); d.pop();
		Test<bool>(9, a.top() < c.top(), b.top() < d.top());
		// Test 10
		Test<bool>(10, a.top() > c.top(), b.top() > d.top());
		// Test 11
		Test<bool>(11, a.top() == c.top(), b.top() == d.top());
		// Test 12
		Test<bool>(12, a.top() != c.top(), b.top() != d.top());
		// Test 13
		Test<bool>(13, a.top() <= c.top(), b.top() <= d.top());
		// Test 14
		Test<bool>(14, a.top() >= c.top(), b.top() >= d.top());
	}
	{
		stack <string, list<string> > a;
		ft::stack <string, list<string> > b;

		// Test 15
		Test<bool>(15, a.empty(), b.empty());
		// Test 16
		a.push("1"); b.push("1");
		Test<bool>(16, a.empty(), b.empty());
		// Test 17
		Test<string>(17, a.top(), b.top());
		// Test 18
		a.pop(); b.pop();
		Test<bool>(18, a.empty(), b.empty());
		// Test 19
		for (int i = 0; i < 10; ++i) {
			a.push("string " + to_string(i + 1));; b.push("string " + to_string(i + 1));;
		}
		Test<size_t>(19, a.size(), b.size());
		// Test 20
		Test<string>(20, a.top(), b.top());
		// Test 21
		stack<string, list<string> > c;
		ft::stack<string, list<string> > d;
		for (int i = 0; i < 20; ++i) {
			c.push("string " + to_string(i + 1));
			d.push("string " + to_string(i + 1));
		}
		a = c;
		b = d;
		Test<size_t>(21, a.size(), b.size());
		// Test 22
		Test<string>(22, a.top(), b.top());
		// Test 23
		c.pop(); d.pop();
		Test<bool>(23, a.top() < c.top(), b.top() < d.top());
		// Test 24
		Test<bool>(24, a.top() > c.top(), b.top() > d.top());
		// Test 25
		Test<bool>(25, a.top() == c.top(), b.top() == d.top());
		// Test 26
		Test<bool>(26, a.top() != c.top(), b.top() != d.top());
		// Test 27
		Test<bool>(27, a.top() <= c.top(), b.top() <= d.top());
		// Test 28
		Test<bool>(28, a.top() >= c.top(), b.top() >= d.top());
	}
	cout << RESET_ALL << endl;
	
}