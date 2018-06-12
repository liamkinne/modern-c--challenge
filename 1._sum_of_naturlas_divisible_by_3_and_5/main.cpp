#include <iostream>
using namespace std;

int main()
{
  int max_value;
  cout << "Enter limit of summation: ";
  cin >> max_value;

  int sum = 0;
  for (int i = 0; i <= max_value; i++) {
  	if ((i % 3 == 0) or (i % 5 == 0)) {
  		sum += i;
  	}
  }

  cout << "Answer: " << sum << endl;
}
