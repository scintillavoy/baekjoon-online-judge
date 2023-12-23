#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  cout << (long long)(N - 1) * (N - 1) << '\n';
  for (int i = 2; i <= N; ++i) {
    cout << 1 << ' ' << i << '\n';
  }
  return 0;
}
