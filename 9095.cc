#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(11, -1);

int calculate(int n) {
  if (n <= 3) {
    return dp[n];
  }
  if (dp[n] == -1) {
    dp[n] = calculate(n - 1) + calculate(n - 2) + calculate(n - 3);
  }
  return dp[n];
}

int main() {
  int T;
  cin >> T;
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  while (T--) {
    int n;
    cin >> n;
    cout << calculate(n) << '\n';
  }
  return 0;
}
