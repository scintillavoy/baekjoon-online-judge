#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int M, N;
  cin >> M >> N;
  vector<bool> sieve(N + 1);
  for (int i = 2; i <= N; ++i) {
    sieve[i] = true;
  }
  for (int i = 2; i <= sqrt(N); ++i) {
    if (!sieve[i]) {
      continue;
    }
    for (int j = i * i; j <= N; j += i) {
      sieve[j] = false;
    }
  }
  int sum_of_primes = 0, min_of_primes;
  for (int i = N; i >= M; --i) {
    if (sieve[i]) {
      sum_of_primes += i;
      min_of_primes = i;
    }
  }
  if (sum_of_primes == 0) {
    cout << -1;
  } else {
    cout << sum_of_primes << '\n' << min_of_primes;
  }
  return 0;
}
