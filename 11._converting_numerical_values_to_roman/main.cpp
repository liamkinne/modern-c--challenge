#include <iostream>
#include <string>
using namespace std;

const char* roman_keys[] = {
	"I",
	"V",
	"X",
	"L",
	"C",
	"D",
	"M"
};

const int roman_values[] = {
	1,
	5,
	10,
	50,
	100, 
	500,
	1000
};

int main() {
	int number;
	cout << "Enter a number: ";
	cin >> number;

	int length_of_values = sizeof(roman_values)/sizeof(int);
	string answer;

	while (number > 0) {
		for (auto i = length_of_values-1; i >= 0; i--) {
			auto value = roman_values[i];
			if ((number >= value) or (value == 1)) {
				number -= value;
				answer += roman_keys[i];
				break;
			}
		}
	}

	cout << "Ruman numeral: " << answer << endl;

}
