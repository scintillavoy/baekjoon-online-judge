#include <iostream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string command;
    cin >> command;
    if (command.size() == 7 && command[0] == command[1] &&
        command[0] == command[4] && command[2] == command[3] &&
        command[2] == command[5] && command[2] == command[6] &&
        command[0] != command[2]) {
      cout << 1;
    } else {
      cout << 0;
    }
    cout << '\n';
  }
  return 0;
}
