#include <iostream>
#include <limits>
#include <sstream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  while (T--) {
    string expression;
    getline(cin, expression);
    istringstream iss(expression);

    double number;
    iss >> number;

    char op;
    while (iss >> op) {
      switch (op) {
        case '@':
          number *= 3;
          break;
        case '%':
          number += 5;
          break;
        case '#':
          number -= 7;
          break;
      }
    }

    cout.precision(2);
    cout << fixed << number << '\n';
  }
  return 0;
}
