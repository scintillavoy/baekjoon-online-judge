#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int max_length = 1;
  int length = 0;
  int prev = 0;
  bool increasing = true;
  while (N--) {
    int A;
    cin >> A;
    if (increasing) {
      if (A > prev) {
        ++length;
      } else if (A < prev) {
        increasing = false;
        ++length;
      } else {
        max_length = max(max_length, length);
        length = 1;
      }
    } else {
      if (A > prev) {
        increasing = true;
        max_length = max(max_length, length);
        length = 2;
      } else if (A < prev) {
        ++length;
      } else {
        increasing = true;
        max_length = max(max_length, length);
        length = 1;
      }
    }
    prev = A;
  }
  max_length = max(max_length, length);
  cout << max_length;
  return 0;
}
