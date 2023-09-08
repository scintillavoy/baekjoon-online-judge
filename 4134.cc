#include <cmath>
#include <iostream>
using namespace std;

bool is_prime(unsigned int n) {
  if (n < 2) {
    return false;
  }
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    unsigned int n;
    cin >> n;
    while (!is_prime(n)) {
      ++n;
    }
    cout << n << '\n';
  }
  return 0;
}
