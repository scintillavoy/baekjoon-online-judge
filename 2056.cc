#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> duration(N + 1);
  vector<vector<int>> graph(N + 1);
  vector<int> in_degree(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> duration[i];
    int num;
    cin >> num;
    in_degree[i] = num;
    while (num--) {
      int prerequisite;
      cin >> prerequisite;
      graph[prerequisite].push_back(i);
    }
  }
  vector<int> min_time(N + 1);
  queue<int> q;
  for (int i = 1; i <= N; ++i) {
    if (in_degree[i] > 0) continue;
    q.push(i);
  }
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    min_time[curr] += duration[curr];
    for (const auto &adj : graph[curr]) {
      min_time[adj] = max(min_time[adj], min_time[curr]);
      --in_degree[adj];
      if (in_degree[adj] == 0) {
        q.push(adj);
      }
    }
  }
  cout << *max_element(min_time.cbegin(), min_time.cend());
  return 0;
}
