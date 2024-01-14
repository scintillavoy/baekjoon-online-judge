#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> towers(N);
  for (int i = 0; i < N; ++i) {
    cin >> towers[i];
  }
  stack<pair<int, int>> s;
  for (int i = 0; i < N; ++i) {
    while (!s.empty() && s.top().first < towers[i]) {
      s.pop();
    }
    if (!s.empty()) {
      cout << s.top().second + 1;
    } else {
      cout << 0;
    }
    cout << ' ';
    s.push({towers[i], i});
  }
  return 0;
}
