#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  cin >> input;
  for (const auto &c : input) {
    cout << char(toupper(c));
  }
  return 0;
}
