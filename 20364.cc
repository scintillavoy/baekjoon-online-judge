#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  vector<bool> occupied(N + 1);
  for (int i = 0; i < Q; ++i) {
    int x;
    cin >> x;
    int answer = 0, curr = x;
    while (curr > 0) {
      if (occupied[curr]) {
        answer = curr;
      }
      curr /= 2;
    }
    if (answer == 0) {
      occupied[x] = true;
    }
    cout << answer << '\n';
  }
  return 0;
}
