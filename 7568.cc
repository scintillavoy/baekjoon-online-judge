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
  for (const auto &x : vec) {
    int rank = 1;
    for (const auto &y : vec) {
      if (x.first < y.first && x.second < y.second) {
        ++rank;
      }
    }
    cout << rank << ' ';
  }
  return 0;
}
