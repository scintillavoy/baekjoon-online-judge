#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    int T;
    cin >> T;
    sum += T + 8;
  }
  sum -= 8;
  cout << sum / 24 << ' ' << sum % 24;
  return 0;
}
