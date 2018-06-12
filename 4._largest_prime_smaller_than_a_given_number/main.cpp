#include <iostream>
using namespace std;

int main() {
	int number;
	cout << "Enter a number: ";
	cin >> number;

	int answer = 0;
	for (int i = number-1; i > 1; i--) {
		bool is_prime = true;

		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				is_prime = false;
				break;
			}
		}

		if (is_prime == true) {
			answer = i;
			break;
		}
	}

	if (answer > 2) {
		cout << answer << " is the largest prime smaller than " << number;
	}
	else {
		cout << "there are no primes smaller than " << number;
	}

	cout << endl;
}
