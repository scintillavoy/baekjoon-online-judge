#include <iostream>
using namespace std;

int main() {
  int K;
  cin >> K;
  int right = 0;
  while ((K & 1) == 0) {
    K >>= 1;
    ++right;
  }
  int left = right;
  while (K > 1) {
    K >>= 1;
    ++left;
  }
  if (left != right) {
    ++left;
  }
  cout << (1 << left) << ' ' << left - right;
  return 0;
}
