#include <iostream>
using namespace std;

int main() {
  int x, y;
  cout << "Enter first value: ";
  cin >> x;
  cout << endl << "Enter second value: ";
  cin >> y;
  cout << endl;

  int smallest = min(x, y);
  int answer = 0;
  for (int i = 2; i <= smallest; i++)
  {
    if ((x % i == 0) and (y % i) == 0) {
      answer = i;
      break;
    }
  }

  if (answer != 0)
    cout << "The answer is: " << answer << endl;
  else
    cout << "There are no common factors" << endl;
}
