#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 10'000'000

int main() {
  vector<bool> sieve(MAX + 1, true);
  sieve[0] = false;
  sieve[1] = false;
  for (int i = 2; i <= sqrt(MAX); ++i) {
    if (!sieve[i]) {
      continue;
    }
    for (int j = i * i; j <= MAX; j += i) {
      sieve[j] = false;
    }
  }
  vector<int> primes;
  for (int i = 2; i <= MAX; ++i) {
    if (sieve[i]) {
      primes.push_back(i);
    }
  }
  int K;
  cin >> K;
  cout << primes[K - 1];
  return 0;
}
