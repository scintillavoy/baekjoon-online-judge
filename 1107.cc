#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int M;
  cin >> M;
  vector<bool> disabled(10);
  for (int i = 0; i < M; ++i) {
    int button;
    cin >> button;
    disabled[button] = true;
  }
  int min_count = abs(100 - N);
  for (int i = max(N - min_count, 0); i <= N + min_count; ++i) {
    string i_str = to_string(i);
    bool is_possible = true;
    for (const auto &digit : i_str) {
      if (disabled[digit - '0']) {
        is_possible = false;
      }
    }
    if (is_possible) {
      min_count = min(min_count, (int)i_str.size() + abs(i - N));
    }
  }
  cout << min_count;
  return 0;
}
