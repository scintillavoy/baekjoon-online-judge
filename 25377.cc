#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int min_time = numeric_limits<int>::max();
  for (int i = 0; i < N; ++i) {
    int A, B;
    cin >> A >> B;
    if (A > B) {
      continue;
    }
    min_time = min(min_time, B);
  }
  cout << (min_time == numeric_limits<int>::max() ? -1 : min_time);
  return 0;
}
