#include <iostream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string str;
    cin >> str;
    int count = 0;
    bool is_valid = true;
    for (const auto &x : str) {
      if (x == '(') {
        ++count;
      } else if (x == ')') {
        if (count <= 0) {
          is_valid = false;
          break;
        }
        --count;
      }
    }
    if (count != 0) {
      is_valid = false;
    }
    cout << (is_valid ? "YES" : "NO") << '\n';
  }
  return 0;
}
