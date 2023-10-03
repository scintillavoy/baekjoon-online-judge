#include <iostream>
using namespace std;

int main() {
  int D, K;
  cin >> D >> K;
  int quotient_A = 1, quotient_B = 0;
  for (int i = 2; i <= D; ++i) {
    int temp = quotient_A;
    quotient_A = quotient_B;
    quotient_B += temp;
  }
  for (int A = 1; true; ++A) {
    if ((K - quotient_A * A) % quotient_B == 0) {
      cout << A << '\n';
      cout << (K - quotient_A * A) / quotient_B;
      return 0;
    }
  }
  return 0;
}
