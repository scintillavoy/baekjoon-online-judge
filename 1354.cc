#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> dp;
int P, Q, X, Y;

long long solve(long long n) {
  if (n <= 0) {
    return 1;
  }
  if (dp.count(n) == 1) {
    return dp[n];
  }
  return dp[n] = solve(n / P - X) + solve(n / Q - Y);
}

int main() {
  long long N;
  cin >> N >> P >> Q >> X >> Y;
  cout << solve(N);
  return 0;
}
