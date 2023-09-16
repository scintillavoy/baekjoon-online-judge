#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 123456

int main() {
  vector<bool> sieve(MAX * 2 + 1, true);
  sieve[0] = false;
  sieve[1] = false;
  for (int i = 2; i <= sqrt(sieve.size()); ++i) {
    if (!sieve[i]) {
      continue;
    }
    for (int j = i * i; j <= sieve.size(); j += i) {
      sieve[j] = false;
    }
  }
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    int count = 0;
    for (int i = n + 1; i <= 2 * n; ++i) {
      if (sieve[i]) {
        ++count;
      }
    }
    cout << count << '\n';
  }
  return 0;
}
