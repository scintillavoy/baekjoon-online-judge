#include <iostream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string input;
    cin >> input;
    cout << input.front() << input.back() << '\n';
  }
  return 0;
}
