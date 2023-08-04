#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (auto &x : S) {
    cin >> x;
  }
  sort(S.begin(), S.end());
  int count = 0;
  for (int i = 0; i < M; ++i) {
    string str;
    cin >> str;
    auto it = lower_bound(S.cbegin(), S.cend(), str);
    if (it == S.cend()) continue;
    if (it->find(str) == 0) ++count;
  }
  cout << count;
  return 0;
}
