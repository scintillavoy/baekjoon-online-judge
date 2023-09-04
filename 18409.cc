#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int count = 0;
  for (const auto &x : S) {
    switch (x) {
      case 'a':
      case 'i':
      case 'u':
      case 'e':
      case 'o':
        ++count;
        break;
    }
  }
  cout << count;
  return 0;
}
