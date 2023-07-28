#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> sequence;

void solve(int depth) {
  if (depth == M) {
    for (const auto &x : sequence) {
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = 1; i <= N; ++i) {
    sequence[depth] = i;
    solve(depth + 1);
  }
}

int main() {
  cin >> N >> M;
  sequence = vector<int>(M);
  solve(0);
  return 0;
}
