#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 1'000'000

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
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 0; i < primes.size(); ++i) {
      if (primes[i] > N / 2) {
        break;
      }
      if (sieve[N - primes[i]]) {
        ++count;
      }
    }
    cout << count << '\n';
  }
  return 0;
}
