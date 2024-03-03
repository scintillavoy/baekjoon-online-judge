#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int stat, sum = 0;
  for (int i = 0; i < 4; ++i) {
    cin >> stat;
    sum += stat;
  }
  int N;
  cin >> N;
  cout << max(0, 4 * N - sum);
  return 0;
}
