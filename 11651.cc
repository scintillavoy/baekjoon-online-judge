#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<int, int>> vec(N);
  for (int i = 0; i < N; ++i) {
    cin >> vec[i].first >> vec[i].second;
  }
  sort(vec.begin(), vec.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         if (a.second != b.second) {
           return a.second < b.second;
         }
         return a.first < b.first;
       });
  for (int i = 0; i < N; ++i) {
    cout << vec[i].first << ' ' << vec[i].second << '\n';
  }
  return 0;
}
