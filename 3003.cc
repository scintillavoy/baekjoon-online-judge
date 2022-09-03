#include <iostream>
using namespace std;

int main() {
  int expect[6] = {1, 1, 2, 2, 2, 8};
  int found[6];
  for (auto &x : found) {
    cin >> x;
  }
  for (int i = 0; i < 6; ++i) {
    cout << expect[i] - found[i] << ' ';
  }
  return 0;
}
