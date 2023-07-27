#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<bool> is_visited;
vector<int> sequence;

void dfs(int depth) {
  if (depth == M) {
    for (const auto &x : sequence) {
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = 1; i <= N; ++i) {
    if (!is_visited[i]) {
      is_visited[i] = true;
      sequence[depth] = i;
      dfs(depth + 1);
      is_visited[i] = false;
    }
  }
}

int main() {
  cin >> N >> M;
  is_visited = vector<bool>(N + 1, false);
  sequence = vector<int>(M);
  dfs(0);
  return 0;
}
