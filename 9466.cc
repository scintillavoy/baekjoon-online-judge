#include <iostream>
#include <vector>
using namespace std;

vector<int> graph;
vector<bool> visited;
vector<bool> finished;
int count_;

void dfs(int curr) {
  visited[curr] = true;
  int next = graph[curr];
  if (!visited[next]) {
    dfs(next);
  } else if (!finished[next]) {
    while (curr != next) {
      next = graph[next];
      ++count_;
    }
    ++count_;
  }
  finished[curr] = true;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    graph = vector<int>(n + 1);
    visited = vector<bool>(n + 1);
    finished = vector<bool>(n + 1);
    count_ = 0;
    for (int i = 1; i <= n; ++i) {
      int number;
      cin >> number;
      graph[i] = number;
    }
    for (int i = 1; i <= n; ++i) {
      if (visited[i]) {
        continue;
      }
      dfs(i);
    }
    cout << n - count_ << '\n';
  }
  return 0;
}
