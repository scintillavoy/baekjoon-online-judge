#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
  int N;
  cin >> N;
  stack<pair<int, int>> stk;
  int max_value = 0;
  for (int i = 0; i < N; ++i) {
    int H;
    cin >> H;
    while (!stk.empty()) {
      auto [height, index] = stk.top();
      if (height <= H) {
        break;
      }
      stk.pop();
      int width = (stk.empty() ? i : i - stk.top().second - 1);
      max_value = max(max_value, height * width);
    }
    stk.push({H, i});
  }
  while (!stk.empty()) {
    auto [height, index] = stk.top();
    stk.pop();
    int width = (stk.empty() ? N : N - stk.top().second - 1);
    max_value = max(max_value, height * width);
  }
  cout << max_value;
  return 0;
}
