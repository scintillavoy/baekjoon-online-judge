#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cout << 0 << ' ' << i + 1 << '\n';
  }
  for (int j = m + 1; j < n; ++j) {
    cout << j - 1 << ' ' << j << '\n';
  }
  return 0;
}
