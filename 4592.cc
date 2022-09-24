#include <iostream>
using namespace std;

int main() {
  int N;
  while (true) {
    cin >> N;
    if (N == 0) {
      break;
    }
    int curr, prev = 0;
    for (int i = 0; i < N; ++i) {
      cin >> curr;
      if (curr != prev) {
        cout << curr << ' ';
        prev = curr;
      }
    }
    cout << "$\n";
  }
  return 0;
}
