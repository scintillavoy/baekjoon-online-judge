#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int cost(int from, int to) {
  if (from == 0) {
    return 2;
  }
  if (from == to) {
    return 1;
  }
  if (abs(from - to) == 2) {
    return 4;
  }
  return 3;
}

int main() {
  vector<int> vec;
  while (true) {
    int num;
    cin >> num;
    if (num == 0) {
      break;
    }
    vec.push_back(num);
  }
  vector<vector<vector<int>>> dp(
      vec.size() + 1,
      vector<vector<int>>(5, vector<int>(5, numeric_limits<int>::max())));
  dp[0][0][0] = 0;
  for (int i = 0; i < vec.size(); ++i) {
    for (int j = 0; j < 5; ++j) {
      for (int k = 0; k < 5; ++k) {
        if (dp[i][j][k] == numeric_limits<int>::max()) {
          continue;
        }
        dp[i + 1][vec[i]][k] =
            min(dp[i + 1][vec[i]][k], dp[i][j][k] + cost(j, vec[i]));
        dp[i + 1][j][vec[i]] =
            min(dp[i + 1][j][vec[i]], dp[i][j][k] + cost(k, vec[i]));
      }
    }
  }
  int min_cost = numeric_limits<int>::max();
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      min_cost = min(min_cost, dp.back()[i][j]);
    }
  }
  cout << min_cost;
  return 0;
}
