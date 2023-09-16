#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int M, N;
  cin >> M >> N;
  vector<bool> sieve(N + 1, true);
  sieve[0] = false;
  sieve[1] = false;
  for (int i = 2; i <= sqrt(N); ++i) {
    if (!sieve[i]) {
      continue;
    }
    for (int j = i * i; j <= N; j += i) {
      sieve[j] = false;
    }
  }
  for (int i = M; i <= N; ++i) {
    if (sieve[i]) {
      cout << i << '\n';
    }
  }
  return 0;
}
