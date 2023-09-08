#include <iostream>
#include <vector>
using namespace std;

#define MAX 10'000

int main() {
  int N;
  cin >> N;
  vector<bool> sieve(MAX + 1, true);
  for (int i = 0; i < 2; ++i) {
    sieve[i] = false;
  }
  int prev_prime = 0;
  for (int i = 2; i <= MAX; ++i) {
    if (!sieve[i]) {
      continue;
    }
    if (prev_prime * i > N) {
      cout << prev_prime * i;
      return 0;
    }
    prev_prime = i;
    for (int j = i * i; j <= MAX; j += i) {
      sieve[j] = false;
    }
  }
  return 0;
}
