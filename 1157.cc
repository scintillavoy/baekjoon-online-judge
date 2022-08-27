#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string word;
  cin >> word;
  int count[26] = {0};
  for (const auto &x : word) {
    ++count[toupper(x) - 'A'];
  }
  int index = 0;
  bool check = false;
  for (int i = 1; i < 26; ++i) {
    if (count[i] > count[index]) {
      index = i;
      check = false;
    } else if (count[i] == count[index]) {
      check = true;
    }
  }
  cout << char(check ? '?' : index + 'A');
  return 0;
}
