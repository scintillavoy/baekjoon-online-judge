#include <iostream>
#include <string>
using namespace std;

int main() {
  while (true) {
    string input;
    getline(cin, input);
    int count = 0;
    for (const auto &x : input) {
      switch (x) {
        case '#':
          return 0;
          break;
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
          ++count;
          break;
      }
    }
    cout << count << '\n';
  }
  return 0;
}
