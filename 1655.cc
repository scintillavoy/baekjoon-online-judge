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
  priority_queue<int> max_pq;
  priority_queue<int, vector<int>, greater<int>> min_pq;
  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    if (min_pq.size() > 0 && num > min_pq.top()) {
      min_pq.push(num);
    } else {
      max_pq.push(num);
    }
    if (max_pq.size() > min_pq.size() + 1) {
      min_pq.push(max_pq.top());
      max_pq.pop();
    } else if (max_pq.size() < min_pq.size()) {
      max_pq.push(min_pq.top());
      min_pq.pop();
    }
    cout << max_pq.top() << '\n';
  }
  return 0;
}
