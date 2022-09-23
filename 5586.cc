#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cin >> str;
  int num_of_JOI = 0, num_of_IOI = 0;
  for (auto it = str.cbegin() + 1; it < str.cend(); ++it) {
    if (*it == 'O' && *(it + 1) == 'I') {
      if (*(it - 1) == 'J') {
        ++num_of_JOI;
      } else if (*(it - 1) == 'I') {
        ++num_of_IOI;
      }
    }
  }
  cout << num_of_JOI << '\n' << num_of_IOI;
  return 0;
}
