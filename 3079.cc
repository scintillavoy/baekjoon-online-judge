#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int> T(N);
  for (int i = 0; i < T.size(); ++i) {
    cin >> T[i];
  }
  int min_time = *min_element(T.cbegin(), T.cend());
  long long left = min_time, right = (long long)min_time * M;
  while (left <= right) {
    long long mid = (left + right) / 2;
    long long finished = 0;
    for (int i = 0; i < T.size(); ++i) {
      finished += mid / T[i];
    }
    if (finished >= M) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << left;
  return 0;
}
