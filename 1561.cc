#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int> durations(M);
  for (int i = 0; i < durations.size(); ++i) {
    cin >> durations[i];
  }
  long long left = 0, right = 2'000'000'000LL * 30;
  while (left <= right) {
    long long mid = (left + right) / 2;
    long long count = 0;
    for (int i = 0; i < durations.size(); ++i) {
      count += mid / durations[i] + 1;
    }
    if (count >= N) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  if (left == 0) {
    cout << N;
    return 0;
  }
  long long count = 0;
  for (int i = 0; i < durations.size(); ++i) {
    count += (left - 1) / durations[i] + 1;
  }
  for (int i = 0; i < durations.size(); ++i) {
    if (left % durations[i] == 0) {
      ++count;
    }
    if (count == N) {
      cout << i + 1;
      break;
    }
  }
  return 0;
}
