#include <deque>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  deque<int> deq;
  for (int i = 1; i <= N; ++i) {
    deq.push_back(i);
  }
  while (deq.size() > 1) {
    deq.pop_front();
    deq.push_back(deq.front());
    deq.pop_front();
  }
  cout << deq.front();
  return 0;
}
