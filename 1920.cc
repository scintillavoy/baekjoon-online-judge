#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  unordered_set<int> S;
  S.reserve(N);
  for (int i = 0; i < N; ++i) {
    int number;
    cin >> number;
    S.insert(number);
  }
  int M;
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int number;
    cin >> number;
    cout << S.count(number) << '\n';
  }
  return 0;
}
