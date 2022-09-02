#include <iostream>
#include <string>
using namespace std;

int main() {
  while (true) {
    string number;
    cin >> number;
    if (number == "0") break;
    bool is_palindrome = true;
    for (int i = 0; i < number.size() / 2; ++i) {
      if (number[i] != number[number.size() - 1 - i]) {
        is_palindrome = false;
        break;
      }
    }
    cout << (is_palindrome ? "yes" : "no") << '\n';
  }
  return 0;
}
