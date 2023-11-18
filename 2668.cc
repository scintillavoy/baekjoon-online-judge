#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> numbers(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> numbers[i];
  }
  int selected_count = 0;
  vector<bool> selected(N + 1);
  for (int i = 1; i <= N; ++i) {
    vector<bool> visited(N + 1);
    stack<int> stk;
    int curr = i;
    while (true) {
      if (visited[curr]) {
        break;
      }
      visited[curr] = true;
      stk.push(curr);
      curr = numbers[curr];
    }
    while (!stk.empty()) {
      int t = stk.top();
      stk.pop();
      if (!selected[t]) {
        ++selected_count;
        selected[t] = true;
      }
      if (t == curr) {
        break;
      }
    }
  }
  cout << selected_count << '\n';
  for (int i = 1; i <= N; ++i) {
    if (selected[i]) {
      cout << i << '\n';
    }
  }
  return 0;
}
