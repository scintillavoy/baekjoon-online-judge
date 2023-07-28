#include <iostream>
#include <queue>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  priority_queue<int> max_heap;
  while (N--) {
    int x;
    cin >> x;
    if (x == 0) {
      if (max_heap.empty()) {
        cout << 0;
      } else {
        cout << max_heap.top();
        max_heap.pop();
      }
      cout << '\n';
    } else {
      max_heap.push(x);
    }
  }
  return 0;
}
