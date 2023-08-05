#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M, V;
  cin >> N >> M >> V;
  vector<int> C(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> C[i];
  }
  while (M--) {
    int K;
    cin >> K;
    ++K;
    if (K > N) {
      K = (K - V) % (N - V + 1) + V;
    }
    cout << C[K] << '\n';
  }
  return 0;
}
