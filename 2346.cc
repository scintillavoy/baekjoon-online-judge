#include <deque>
#include <iostream>
#include <utility>
using namespace std;

int main() {
  int N;
  cin >> N;
  deque<pair<int, int>> balloons;
  for (int i = 1; i <= N; ++i) {
    int num;
    cin >> num;
    balloons.push_back(make_pair(i, num));
  }
  while (!balloons.empty()) {
    pair<int, int> curr = balloons.front();
    cout << curr.first << ' ';
    balloons.pop_front();
    if (curr.second > 0) {
      for (int i = 0; i < curr.second - 1; ++i) {
        balloons.push_back(balloons.front());
        balloons.pop_front();
      }
    } else {
      for (int i = 0; i < -curr.second; ++i) {
        balloons.push_front(balloons.back());
        balloons.pop_back();
      }
    }
  }
  return 0;
}
