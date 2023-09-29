#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
  int n;
  cin >> n;
  stack<pair<int, int>> stk;
  long long max_value = 0;
  for (int i = 0; i < n; ++i) {
    int T;
    cin >> T;
    while (!stk.empty()) {
      auto [height, index] = stk.top();
      if (height <= T) {
        break;
      }
      stk.pop();
      int width = (stk.empty() ? i : i - stk.top().second - 1);
      max_value = max(max_value, (long long)height * width);
    }
    stk.push({T, i});
  }
  while (!stk.empty()) {
    auto [height, index] = stk.top();
    stk.pop();
    int width = (stk.empty() ? n : n - stk.top().second - 1);
    max_value = max(max_value, (long long)height * width);
  }
  cout << max_value;
  return 0;
}
