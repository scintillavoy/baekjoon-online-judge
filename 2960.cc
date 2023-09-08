#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<bool> sieve(N + 1, true);
  sieve[0] = false;
  sieve[1] = false;
  for (int i = 2; i <= N; ++i) {
    if (!sieve[i]) {
      continue;
    }
    for (int j = i; j <= N; j += i) {
      if (!sieve[j]) {
        continue;
      }
      sieve[j] = false;
      --K;
      if (K == 0) {
        cout << j;
        return 0;
      }
    }
  }
  return 0;
}
