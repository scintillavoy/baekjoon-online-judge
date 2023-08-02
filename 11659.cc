#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int> vec(N + 1, 0);
  for (int i = 1; i <= N; ++i) {
    int num;
    cin >> num;
    vec[i] = vec[i - 1] + num;
  }
  while (M--) {
    int i, j;
    cin >> i >> j;
    cout << vec[j] - vec[i - 1] << '\n';
  }
  return 0;
}
