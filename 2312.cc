#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    for (int i = 2; N > 1; ++i) {
      int count = 0;
      while (N % i == 0) {
        N /= i;
        ++count;
      }
      if (count > 0) {
        cout << i << ' ' << count << '\n';
      }
    }
  }
  return 0;
}
