#include <iostream>
#include <utility>
using namespace std;

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
  long long s = (long long)p1.first * p2.second +
                (long long)p2.first * p3.second +
                (long long)p3.first * p1.second;
  s -= (long long)p2.first * p1.second + (long long)p3.first * p2.second +
       (long long)p1.first * p3.second;
  if (s > 0) {
    return 1;
  }
  if (s < 0) {
    return -1;
  }
  return 0;
}

bool is_intersection(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3,
                     pair<int, int> p4) {
  int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
  int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
  if (p1p2 == 0 && p3p4 == 0) {
    if (p1 > p2) {
      swap(p1, p2);
    }
    if (p3 > p4) {
      swap(p3, p4);
    }
    return p3 <= p2 && p1 <= p4;
  }
  return p1p2 <= 0 && p3p4 <= 0;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  pair<int, int> p1, p2, p3, p4;
  cin >> p1.first >> p1.second >> p2.first >> p2.second;
  cin >> p3.first >> p3.second >> p4.first >> p4.second;
  cout << (is_intersection(p1, p2, p3, p4) ? 1 : 0);
  return 0;
}
