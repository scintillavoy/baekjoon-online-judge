#include <cctype>
#include <iostream>
using namespace std;

int main() {
  int count = 0;
  char c;
  for (int i = 0; cin >> c; ++i) {
    if (isupper(c) && i % 4 != 0) {
      count += 4 - i % 4;
      i = 0;
    }
  }
  cout << count;
}
