#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> parent(N + 1);
    for (int i = 0; i < N - 1; ++i) {
      int A, B;
      cin >> A >> B;
      parent[B] = A;
    }
    int A, B;
    cin >> A >> B;
    vector<bool> visited(N + 1);
    while (A != 0) {
      visited[A] = true;
      A = parent[A];
    }
    while (!visited[B]) {
      B = parent[B];
    }
    cout << B << '\n';
  }
  return 0;
}
