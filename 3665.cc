#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
outer_loop:
  while (T--) {
    int n;
    cin >> n;
    vector<unordered_set<int>> graph(n + 1);
    vector<int> in_degree(n + 1);
    vector<int> previous_order(n);
    for (int i = 0; i < n; ++i) {
      cin >> previous_order[i];
      for (int j = 0; j < i; ++j) {
        graph[previous_order[j]].insert(previous_order[i]);
        ++in_degree[previous_order[i]];
      }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      if (graph[a].count(b) == 0) {
        swap(a, b);
      }
      graph[a].erase(b);
      --in_degree[b];
      graph[b].insert(a);
      ++in_degree[a];
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
      if (in_degree[i] == 0) {
        q.push(i);
      }
    }
    vector<int> finished;
    while (!q.empty()) {
      if (q.size() > 1) {
        cout << "?\n";
        goto outer_loop;
      }
      int curr = q.front();
      q.pop();
      finished.push_back(curr);
      for (const auto &adj : graph[curr]) {
        --in_degree[adj];
        if (in_degree[adj] == 0) {
          q.push(adj);
        }
      }
    }
    if (finished.size() != n) {
      cout << "IMPOSSIBLE\n";
      goto outer_loop;
    }
    for (int i = 0; i < finished.size(); ++i) {
      cout << finished[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
