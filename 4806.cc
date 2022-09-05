#include <iostream>
#include <string>
using namespace std;

int main() {
  int count = 0;
  string input;
  while (getline(cin, input)) {
    ++count;
  }
  cout << count;
  return 0;
}
