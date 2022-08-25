#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string word;
  cin >> word;
  for (const auto &x : word) {
    cout << char(isupper(x) ? tolower(x) : toupper(x));
  }
  return 0;
}
