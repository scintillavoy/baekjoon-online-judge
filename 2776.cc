#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    unordered_set<int> s;
    for (int i = 0; i < N; ++i) {
      int number;
      cin >> number;
      s.insert(number);
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
      int number;
      cin >> number;
      cout << s.count(number) << '\n';
    }
  }
  return 0;
}
