#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  string line;
  while (getline(cin, line)) {
    if (line == "END") {
      break;
    }
    for (auto it = line.crbegin(); it != line.crend(); ++it) {
      cout << *it;
    }
    cout << '\n';
  }
  return 0;
}
