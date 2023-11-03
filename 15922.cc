#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<int, int>> lines(N);
  for (int i = 0; i < N; ++i) {
    cin >> lines[i].first >> lines[i].second;
  }
  int total_length = 0;
  int last_index = lines[0].first;
  for (int i = 0; i < N; ++i) {
    if (last_index < lines[i].first) {
      last_index = lines[i].first;
    }
    total_length += max(0, lines[i].second - last_index);
    last_index = max(last_index, lines[i].second);
  }
  cout << total_length;
  return 0;
}
