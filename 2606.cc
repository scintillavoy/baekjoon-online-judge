#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int num_of_nodes;
  cin >> num_of_nodes;
  vector<vector<int>> graph(num_of_nodes + 1);

  int num_of_edges;
  cin >> num_of_edges;
  for (int i = 0; i < num_of_edges; ++i) {
    int from, to;
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  vector<bool> is_visited(num_of_nodes + 1, false);
  stack<int> dfs_stack;
  dfs_stack.push(1);
  while (!dfs_stack.empty()) {
    int current = dfs_stack.top();
    dfs_stack.pop();
    if (is_visited[current]) continue;
    is_visited[current] = true;
    for (const auto &adj : graph[current]) {
      if (!is_visited[adj]) {
        dfs_stack.push(adj);
      }
    }
  }

  int sum = 0;
  for (const auto &x : is_visited) {
    if (x) ++sum;
  }
  cout << sum - 1;
  return 0;
}
