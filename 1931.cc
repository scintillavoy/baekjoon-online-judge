#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> vec(N);
  for (auto &x : vec) {
    cin >> x.first >> x.second;
  }
  sort(vec.begin(), vec.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         if (a.second != b.second) {
           return a.second < b.second;
         }
         return a.first < b.first;
       });
  int count = 0;
  int last_finish_time = 0;
  for (const auto &x : vec) {
    if (x.first < last_finish_time) continue;
    ++count;
    last_finish_time = x.second;
  }
  cout << count;
  return 0;
}
