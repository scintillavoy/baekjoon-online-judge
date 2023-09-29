#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    stack<pair<int, int>> stk;
    long long max_value = 0;
    for (int i = 0; i < n; ++i) {
      int h;
      cin >> h;
      while (!stk.empty()) {
        auto [height, index] = stk.top();
        if (height <= h) {
          break;
        }
        stk.pop();
        int width = (stk.empty() ? i : i - stk.top().second - 1);
        max_value = max(max_value, (long long)height * width);
      }
      stk.push({h, i});
    }
    while (!stk.empty()) {
      auto [height, index] = stk.top();
      stk.pop();
      int width = (stk.empty() ? n : n - stk.top().second - 1);
      max_value = max(max_value, (long long)height * width);
    }
    cout << max_value << '\n';
  }
  return 0;
}
