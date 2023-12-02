#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> scc_id;
int scc_count = 0;
vector<int> scc_size;
vector<int> start_time;
int current_time = 0;
vector<int> lowlink;
stack<int> s;

void dfs(int curr) {
  start_time[curr] = ++current_time;
  lowlink[curr] = start_time[curr];
  s.push(curr);
  for (const auto &adj : graph[curr]) {
    if (start_time[adj] == 0) {
      dfs(adj);
      lowlink[curr] = min(lowlink[curr], lowlink[adj]);
    } else if (scc_id[adj] == 0) {
      lowlink[curr] = min(lowlink[curr], start_time[adj]);
    }
  }
  if (lowlink[curr] == start_time[curr]) {
    ++scc_count;
    scc_size.push_back(0);
    while (true) {
      int t = s.top();
      s.pop();
      scc_id[t] = scc_count;
      ++scc_size.back();
      if (t == curr) {
        break;
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int D;
  cin >> D;
  graph = vector<vector<int>>(D + 1);
  scc_id = vector<int>(D + 1);
  start_time = vector<int>(D + 1);
  lowlink = vector<int>(D + 1);
  int L;
  cin >> L;
  for (int i = 0; i < L; ++i) {
    int from, to;
    cin >> from >> to;
    graph[from].push_back(to);
  }
  for (int i = 1; i <= D; ++i) {
    if (start_time[i] == 0) {
      dfs(i);
    }
  }
  cout << *max_element(scc_size.cbegin(), scc_size.cend());
  return 0;
}
