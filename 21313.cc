#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N / 2; ++i) {
    cout << 1 << ' ' << 2 << ' ';
  }
  if (N % 2 != 0) {
    cout << 3;
  }
  return 0;
}
