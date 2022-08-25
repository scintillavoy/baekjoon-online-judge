#include <iostream>
using namespace std;

int main() {
  char c;
  cin >> c;
  double credit = 0;
  switch (c) {
    case 'A':
      credit = 4;
      break;
    case 'B':
      credit = 3;
      break;
    case 'C':
      credit = 2;
      break;
    case 'D':
      credit = 1;
      break;
  }
  if (c != 'F') {
    cin >> c;
    switch (c) {
      case '+':
        credit += 0.3;
        break;
      case '-':
        credit -= 0.3;
        break;
    }
  }
  cout.precision(1);
  cout << fixed << credit;
  return 0;
}
