#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> cards;
vector<vector<int>> dp;

int solve(int start, int end, bool turn) {
  if (start > end) {
    return 0;
  }
  if (dp[start][end] != 0) {
    return dp[start][end];
  }
  if (turn) {
    dp[start][end] = max(cards[start] + solve(start + 1, end, !turn),
                         cards[end] + solve(start, end - 1, !turn));
  } else {
    dp[start][end] =
        min(solve(start + 1, end, !turn), solve(start, end - 1, !turn));
  }
  return dp[start][end];
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    cards = vector<int>(N);
    for (int i = 0; i < cards.size(); ++i) {
      cin >> cards[i];
    }
    dp = vector<vector<int>>(N, vector<int>(N));
    cout << solve(0, N - 1, true) << '\n';
  }
  return 0;
}
