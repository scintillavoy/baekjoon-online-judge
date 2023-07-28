#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  int my_atk;
  cin >> my_atk;
  --N;

  priority_queue<int, vector<int>, greater<int>> pq;
  while (N--) {
    int atk;
    cin >> atk;
    pq.push(atk);
    while (!pq.empty() && pq.top() < my_atk) {
      my_atk = min(my_atk + pq.top(), 1000000001);
      pq.pop();
    }
  }

  cout << (pq.empty() ? "Yes" : "No");
  return 0;
}
