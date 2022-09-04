#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  int count[26] = {0};
  for (const auto &x : S) {
    ++count[tolower(x) - 'a'];
  }
  for (const auto &x : count) {
    cout << x << ' ';
  }
  return 0;
}
