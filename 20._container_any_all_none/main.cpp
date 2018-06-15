#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool any(vector<auto> source_list, initializer_list<auto> test_list) {
	for (source : source_list) {
		for (test : test_list) {
			if (source == test)
				return true;
		}
	}
	return false;
}

bool none(vector<auto> source_list, initializer_list<auto> test_list) {
	for (source : source_list) {
		for (test : test_list) {
			if (source == test)
				return false;
		}
	}
	return true;
}

bool all(vector<auto> source_list, initializer_list<auto> input_list) {
	vector<int> test_list = input_list;

	for (source : source_list) {
		for (test : test_list) {
			if (source == test)
				break;
			else if (test == test_list.back())
				return false;
		}
	}
	return true;
}


int main() {
	vector<int> v = {11, 14, 16, 25, 128};
	auto any_of = any(v, {11, 15});
	cout << any_of << endl;
	auto none_of = none(v, {13});
	cout << none_of << endl;
	auto all_of = all(v, {11, 14, 16, 25, 128});
	cout << all_of << endl;
	return 0;
}
