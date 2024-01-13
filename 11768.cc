#include <iostream>
#include <utility>
using namespace std;

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
  int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
  s -= p2.first * p1.second + p3.first * p2.second + p1.first * p3.second;
  if (s > 0) {
    return 1;
  }
  if (s < 0) {
    return -1;
  }
  return 0;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  pair<int, int> p1, p2, p3;
  cin >> p1.first >> p1.second;
  cin >> p2.first >> p2.second;
  cin >> p3.first >> p3.second;
  cout << ccw(p1, p2, p3);
  return 0;
}
