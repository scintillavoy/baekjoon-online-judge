#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string input;
    cin >> input;
    list<char> password;
    auto it = password.begin();
    for (const auto &x : input) {
      switch (x) {
        case '<':
          if (it == password.begin()) continue;
          --it;
          break;
        case '>':
          if (it == password.end()) continue;
          ++it;
          break;
        case '-':
          if (it == password.begin()) continue;
          --it;
          it = password.erase(it);
          break;
        default:
          it = password.insert(it, x);
          ++it;
          break;
      }
    }
    for (const auto &x : password) {
      cout << x;
    }
    cout << '\n';
  }
  return 0;
}
