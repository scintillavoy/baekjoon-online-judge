#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  auto cmp = [](const int a, const int b) {
    if (abs(a) == abs(b)) {
      return a > b;
    }
    return abs(a) > abs(b);
  };
  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
  while (N--) {
    int x;
    cin >> x;
    if (x == 0) {
      if (pq.empty()) {
        cout << 0;
      } else {
        cout << pq.top();
        pq.pop();
      }
      cout << '\n';
    } else {
      pq.push(x);
    }
  }
  return 0;
}
