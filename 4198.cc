#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> weights(N);
  for (int i = 0; i < N; ++i) {
    cin >> weights[i];
  }
  int max_length = 0;
  for (int i = 0; i < N; ++i) {
    vector<int> lis{weights[i]}, lds{weights[i]};
    for (int j = i + 1; j < N; ++j) {
      if (weights[j] > lis.back()) {
        lis.push_back(weights[j]);
      } else {
        auto it = lower_bound(lis.begin(), lis.end(), weights[j]);
        if (it != lis.begin()) {
          *it = weights[j];
        }
      }
      if (weights[j] < lds.back()) {
        lds.push_back(weights[j]);
      } else {
        auto it = lower_bound(lds.rbegin(), lds.rend(), weights[j]);
        --it;
        if (it != lds.rend() - 1) {
          *it = weights[j];
        }
      }
    }
    max_length = max(max_length, (int)lis.size() + (int)lds.size() - 1);
  }
  cout << max_length;
  return 0;
}
