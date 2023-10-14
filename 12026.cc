#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string blocks;
  cin >> blocks;
  vector<int> dp(N, numeric_limits<int>::max());
  dp[0] = 0;
  for (int i = 0; i < N; ++i) {
    if (dp[i] == numeric_limits<int>::max()) {
      continue;
    }
    char next_block;
    switch (blocks[i]) {
      case 'B':
        next_block = 'O';
        break;
      case 'O':
        next_block = 'J';
        break;
      case 'J':
        next_block = 'B';
        break;
    }
    for (int j = i + 1; j < N; ++j) {
      if (blocks[j] != next_block) {
        continue;
      }
      dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
    }
  }
  cout << (dp.back() == numeric_limits<int>::max() ? -1 : dp.back());
  return 0;
}
