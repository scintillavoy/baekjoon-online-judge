#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> dp;
int P, Q;

long long solve(long long n) {
  if (dp.count(n) == 1) {
    return dp[n];
  }
  return dp[n] = solve(n / P) + solve(n / Q);
}

int main() {
  long long N;
  cin >> N >> P >> Q;
  dp[0] = 1;
  cout << solve(N);
  return 0;
}
