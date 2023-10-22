#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int K, M, P;
    cin >> K >> M >> P;
    vector<vector<int>> graph(M + 1);
    vector<int> in_degree(M + 1);
    vector<int> order(M + 1);
    vector<bool> promoted(M + 1);
    while (P--) {
      int A, B;
      cin >> A >> B;
      graph[A].push_back(B);
      ++in_degree[B];
    }
    queue<int> q;
    for (int i = 1; i <= M; ++i) {
      if (in_degree[i] == 0) {
        order[i] = 1;
        q.push(i);
      }
    }
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (const auto &adj : graph[curr]) {
        if (order[adj] < order[curr]) {
          order[adj] = order[curr];
          promoted[adj] = false;
        } else if (order[adj] == order[curr]) {
          if (promoted[adj]) {
            promoted[adj] = false;
          } else {
            ++order[adj];
            promoted[adj] = true;
          }
        }
        --in_degree[adj];
        if (in_degree[adj] == 0) {
          q.push(adj);
        }
      }
    }
    cout << K << ' ' << order[M] << '\n';
  }
  return 0;
}
