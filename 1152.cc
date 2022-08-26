#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);
  int count = 1;
  for (const auto &x : input) {
    if (x == ' ') ++count;
  }
  if (input.front() == ' ') --count;
  if (input.back() == ' ') --count;
  cout << count;
  return 0;
}
