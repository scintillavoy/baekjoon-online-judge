#include <deque>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> distance_(100'001, numeric_limits<int>::max());
  distance_[N] = 0;
  deque<int> dq;
  dq.push_front(N);
  while (!dq.empty()) {
    int curr = dq.front();
    dq.pop_front();
    if (curr - 1 >= 0 && distance_[curr - 1] > distance_[curr] + 1) {
      distance_[curr - 1] = distance_[curr] + 1;
      dq.push_back({curr - 1});
    }
    if (curr + 1 <= 100'000 && distance_[curr + 1] > distance_[curr] + 1) {
      distance_[curr + 1] = distance_[curr] + 1;
      dq.push_back({curr + 1});
    }
    if (curr * 2 <= 100'000 && distance_[curr * 2] > distance_[curr]) {
      distance_[curr * 2] = distance_[curr];
      dq.push_front({curr * 2});
    }
  }
  cout << distance_[K];
  return 0;
}
