#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int number;
  cin >> number;
  vector<int> lis;
  lis.push_back(number);
  for (int i = 1; i < N; ++i) {
    cin >> number;
    auto it = lower_bound(lis.begin(), lis.end(), number);
    if (it == lis.end()) {
      lis.push_back(number);
    } else {
      *it = number;
    }
  }
  cout << N - lis.size();
  return 0;
}
