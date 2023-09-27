#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int count = N / 5;
  N = N % 5;
  while (N % 3 != 0 && count > 0) {
    N += 5;
    --count;
  }
  count += N / 3;
  N = N % 3;
  cout << (N == 0 ? count : -1);
  return 0;
}
