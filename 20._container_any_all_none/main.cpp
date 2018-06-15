#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
bool any(vector<T> source_list, initializer_list<T> test_list) {
	for (source : source_list) {
		for (test : test_list) {
			if (source == test)
				return true;
		}
	}
	return false;
}

template <typename T>
bool none(vector<T> source_list, initializer_list<T> test_list) {
	for (source : source_list) {
		for (test : test_list) {
			if (source == test)
				return false;
		}
	}
	return true;
}

template <typename T>
bool all(vector<T> source_list, initializer_list<T> input_list) {
	vector<T> test_list = input_list;

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
