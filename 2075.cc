#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < N * N; ++i) {
    int x;
    cin >> x;
    pq.push(x);
    if (pq.size() > N) {
      pq.pop();
    }
  }
  cout << pq.top();
  return 0;
}
