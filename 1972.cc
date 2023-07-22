#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

void solve(const string &str) {
  for (int i = 0; i <= int(str.length()) - 2; ++i) {
    unordered_set<string> pairs;
    for (int j = 0; j + i + 1 < str.length(); ++j) {
      string pair = str.substr(j, 1) + str.substr(j + i + 1, 1);
      if (pairs.count(pair) == 1) {
        cout << str << " is NOT surprising." << '\n';
        return;
      }
      pairs.insert(pair);
    }
  }
  cout << str << " is surprising." << '\n';
}

int main() {
  while (true) {
    string str;
    cin >> str;
    if (str == "*") {
      break;
    }
    solve(str);
  }
  return 0;
}
