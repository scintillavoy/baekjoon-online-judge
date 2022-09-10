#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n-- > 0) {
    int first;
    cin >> first;
    while (n-- > 0) {
      int number;
      cin >> number;
      if (number % first == 0) {
        cout << number << '\n';
        break;
      }
    }
  }
  return 0;
}
