#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  if (N < 149) {
    cout << 99;
  } else if (99 - N % 100 <= N % 100 + 1) {
    cout << N - N % 100 + 99;
  } else {
    cout << N - N % 100 - 1;
  }
  return 0;
}
