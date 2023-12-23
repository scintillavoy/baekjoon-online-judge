#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<vector<int>> graph(N + 1);
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int t, k;
    cin >> t >> k;
    if (t == 1) {
      cout << (graph[k].size() > 1 ? "yes" : "no");
    } else if (t == 2) {
      cout << "yes";
    }
    cout << '\n';
  }
  return 0;
}
