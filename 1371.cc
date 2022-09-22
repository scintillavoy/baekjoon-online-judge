#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int counts[26] = {0};
  string line;
  while (getline(cin, line)) {
    for (const auto &x : line) {
      if (islower(x)) {
        ++counts[x - 'a'];
      }
    }
  }
  int max_count = *max_element(counts, counts + 26);
  for (int i = 0; i < 26; ++i) {
    if (counts[i] == max_count) {
      cout << char(i + 'a');
    }
  }
  return 0;
}
