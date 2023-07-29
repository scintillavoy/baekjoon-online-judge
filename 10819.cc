#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  deque<int> dq;
  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    dq.push_back(num);
  }
  sort(dq.begin(), dq.end());
  int min_num = dq.front(), max_num = dq.back();
  dq.pop_front();
  dq.pop_back();
  int sum = max_num - min_num;
  while (dq.size() > 1) {
    sum += max_num - dq.front();
    sum += dq.back() - min_num;
    min_num = dq.front();
    max_num = dq.back();
    dq.pop_front();
    dq.pop_back();
  }
  if (dq.size() == 1) {
    sum += max(abs(dq.front() - max_num), abs(dq.front() - min_num));
  }
  cout << sum;
  return 0;
}
