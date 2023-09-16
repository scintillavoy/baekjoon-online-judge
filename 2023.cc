#include <cmath>
#include <iostream>
using namespace std;

bool is_prime(int n) {
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

void dfs(int curr, int N) {
  if (N == 0) {
    cout << curr << '\n';
    return;
  }
  for (int i = 1; i < 10; ++i) {
    int next = curr * 10 + i;
    if (is_prime(next)) {
      dfs(next, N - 1);
    }
  }
}

int main() {
  int N;
  cin >> N;
  dfs(0, N);
  return 0;
}
