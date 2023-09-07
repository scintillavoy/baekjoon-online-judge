#include <cmath>
#include <iostream>
using namespace std;

bool is_prime(int N) {
  if (N <= 1) {
    return false;
  }
  for (int i = 2; i <= sqrt(N); ++i) {
    if (N % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  int count = 0;
  while (N--) {
    int number;
    cin >> number;
    if (is_prime(number)) {
      ++count;
    }
  }
  cout << count;
  return 0;
}
