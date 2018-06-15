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
		for (auto i = 1; i < length_of_values-1; i--) {
			auto high_value = roman_values[i];
			auto low_value = roman_values[i-1];
			cout << number << endl;
			auto high_delta = abs(high_value-number);
			auto low_delta = abs(number-low_value);
			if ((high_delta < low_delta) and (low_delta == 0)) {
				number -= high_value;
				answer += roman_keys[i];
				break;
			}
			else {
				number -= low_value;
				answer += roman_keys[i-1];
				break;
			}
			
		}
	}

	cout << "Ruman numeral: " << answer << endl;

}
