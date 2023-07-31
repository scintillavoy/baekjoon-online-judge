#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  while (true) {
    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) break;
    unordered_set<int> numbers;
    for (int i = 0; i < N; ++i) {
      int number;
      cin >> number;
      numbers.insert(number);
    }
    int count = 0;
    for (int i = 0; i < M; ++i) {
      int number;
      cin >> number;
      count += numbers.count(number);
    }
    cout << count << '\n';
  }
  return 0;
}
