#include "color.hpp"
#include "../vector.hpp"
#include "Test.hpp"
#include <vector>

using namespace std;

int main(void) {

	cout << FG_YELLOW << "VECTOR TEST" << endl;
	vector<int> std_v;
	ft::vector<int> ft_v;

	// test 1
	Test<bool>(1, std_v.empty(), ft_v.empty());
	// test 2
	Test<size_t>(2, std_v.size(), ft_v.size());
	// test 3
	Test<size_t>(3, std_v.capacity(), ft_v.capacity());
	// test 4
	std_v.reserve(10); ft_v.reserve(10);
	Test<size_t>(4, std_v.capacity(), ft_v.capacity());
	// test 5
	std_v.push_back(17); ft_v.push_back(17);
	Test<size_t>(5, std_v.size(), ft_v.size());
	// test 6
	Test<int>(6, std_v[0], ft_v[0]);
	// test 7
	std_v.resize(7, 4); ft_v.resize(7, 4);
	Test<size_t>(7, std_v.size(), ft_v.size());
	// test 8
	std_v.push_back(2); ft_v.push_back(2);
	Test<size_t>(8, std_v.capacity(), ft_v.capacity());
	// test 9
	// std_v.pop_back(); ft_v.pop_back();
	Test<size_t>(9, std_v.size(), ft_v.size());
	// test 10
	Test<int>(10, std_v[std_v.size() - 1], ft_v[ft_v.size() - 1]);


	cout << RESET_ALL << endl;


}