#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> steps(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> steps[i];
  }
  int a, b;
  cin >> a >> b;
  vector<bool> visited(N + 1);
  queue<pair<int, int>> q;
  visited[a] = true;
  q.push({a, 0});
  while (!q.empty()) {
    auto [curr, distance] = q.front();
    q.pop();
    if (curr == b) {
      cout << distance;
      return 0;
    }
    for (int next = curr + steps[curr]; next <= N; next += steps[curr]) {
      if (visited[next]) {
        continue;
      }
      visited[next] = true;
      q.push({next, distance + 1});
    }
    for (int next = curr - steps[curr]; next > 0; next -= steps[curr]) {
      if (visited[next]) {
        continue;
      }
      visited[next] = true;
      q.push({next, distance + 1});
    }
  }
  cout << -1;
  return 0;
}
