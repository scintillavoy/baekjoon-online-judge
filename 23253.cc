#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  bool result = true;
  while (M--) {
    int k;
    cin >> k;
    int max_num = N + 1;
    while (k--) {
      int number;
      cin >> number;
      if (number < max_num) {
        max_num = number;
      } else {
        result = false;
      }
    }
  }

  cout << (result ? "Yes" : "No");
  return 0;
}
