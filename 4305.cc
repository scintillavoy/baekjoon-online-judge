#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> scc_id;
int current_scc_id = 0;
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
    ++current_scc_id;
    while (true) {
      int t = s.top();
      s.pop();
      scc_id[t] = current_scc_id;
      if (t == curr) {
        break;
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  while (true) {
    int N;
    cin >> N;
    if (N == 0) {
      break;
    }
    graph = vector<vector<int>>(26);
    scc_id = vector<int>(26);
    current_scc_id = 0;
    start_time = vector<int>(26, -1);
    current_time = 0;
    lowlink = vector<int>(26);
    for (int i = 0; i < N; ++i) {
      vector<char> activities(5);
      for (int j = 0; j < 5; ++j) {
        cin >> activities[j];
        start_time[activities[j] - 'A'] = 0;
      }
      char chosen;
      cin >> chosen;
      for (int j = 0; j < 5; ++j) {
        if (chosen == activities[j]) {
          continue;
        }
        graph[activities[j] - 'A'].push_back(chosen - 'A');
      }
    }
    for (int i = 0; i < 26; ++i) {
      if (start_time[i] == 0) {
        dfs(i);
      }
    }
    for (int i = 0; i < 26; ++i) {
      if (start_time[i] > 0) {
        cout << char('A' + i);
        int id = scc_id[i];
        for (int j = i + 1; j < 26; ++j) {
          if (scc_id[j] == id) {
            cout << ' ' << char('A' + j);
            start_time[j] = -1;
          }
        }
        cout << '\n';
      }
    }
    cout << '\n';
  }
  return 0;
}
