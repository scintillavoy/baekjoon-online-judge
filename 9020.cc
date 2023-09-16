#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 10000

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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int prime;
    for (int i = n / 2; i >= 2; --i) {
      if (sieve[i] && sieve[n - i]) {
        prime = i;
        break;
      }
    }
    cout << prime << ' ' << n - prime << '\n';
  }
  return 0;
}
