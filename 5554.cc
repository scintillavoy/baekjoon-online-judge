#include <iostream>
using namespace std;

int main() {
  int total_seconds = 0;
  for (int i = 0; i < 4; ++i) {
    int seconds;
    cin >> seconds;
    total_seconds += seconds;
  }
  cout << total_seconds / 60 << '\n';
  cout << total_seconds % 60;
  return 0;
}
