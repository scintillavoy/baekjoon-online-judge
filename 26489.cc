#include <iostream>
#include <string>
using namespace std;

int main() {
  string line;
  int count = 0;
  while (getline(cin, line)) {
    ++count;
  }
  cout << count;
  return 0;
}
