#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int A, B, C;
  cin >> A >> B >> C;
  vector<vector<vector<bool>>> visited(
      A + 1, vector<vector<bool>>(B + 1, vector<bool>(C + 1)));
  vector<int> answers;
  queue<tuple<int, int, int>> q;
  q.push({0, 0, C});
  while (!q.empty()) {
    auto [a, b, c] = q.front();
    q.pop();
    if (visited[a][b][c]) {
      continue;
    }
    visited[a][b][c] = true;
    if (a == 0) {
      answers.push_back(c);
    }
    if (a + b <= B) {
      q.push({0, a + b, c});
    } else {
      q.push({a + b - B, B, c});
    }
    if (a + c <= C) {
      q.push({0, b, a + c});
    } else {
      q.push({a + b - C, b, C});
    }
    if (b + a <= A) {
      q.push({b + a, 0, c});
    } else {
      q.push({A, b + a - A, c});
    }
    if (b + c <= C) {
      q.push({a, 0, b + c});
    } else {
      q.push({a, b + c - C, C});
    }
    if (c + a <= A) {
      q.push({c + a, b, 0});
    } else {
      q.push({A, b, c + a - A});
    }
    if (c + b <= B) {
      q.push({a, c + b, 0});
    } else {
      q.push({a, B, c + b - B});
    }
  }
  sort(answers.begin(), answers.end());
  for (const auto &x : answers) {
    cout << x << ' ';
  }
  return 0;
}
