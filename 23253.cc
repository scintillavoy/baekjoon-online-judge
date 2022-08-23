#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  bool result = true;
  while (M--) {
    int k;
    cin >> k;
    int maxNum = N + 1;
    while (k--) {
      int number;
      cin >> number;
      if (number < maxNum) {
        maxNum = number;
      } else {
        result = false;
      }
    }
  }

  cout << (result ? "Yes" : "No");
  return 0;
}
