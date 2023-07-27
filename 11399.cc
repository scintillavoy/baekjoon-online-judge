#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (auto &x : P) {
    cin >> x;
  }
  sort(P.begin(), P.end());
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += P[i] * (N - i);
  }
  cout << sum;
  return 0;
}
