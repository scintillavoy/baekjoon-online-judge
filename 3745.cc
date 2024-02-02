#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  while (cin >> N) {
    if (N <= 0) {
      continue;
    }
    vector<int> vec;
    for (int i = 0; i < N; ++i) {
      int num;
      cin >> num;
      if (vec.empty() || vec.back() < num) {
        vec.push_back(num);
      } else {
        auto it = lower_bound(vec.begin(), vec.end(), num);
        *it = num;
      }
    }
    cout << vec.size() << '\n';
  }
  return 0;
}
