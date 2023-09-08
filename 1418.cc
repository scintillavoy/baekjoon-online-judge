#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> vec(N + 1);
  for (int i = 2; i <= N; ++i) {
    if (vec[i] != 0) {
      continue;
    }
    for (int j = i; j <= N; j += i) {
      vec[j] = i;
    }
  }
  int count = 0;
  for (int i = 1; i <= N; ++i) {
    if (vec[i] <= K) {
      ++count;
    }
  }
  cout << count;
  return 0;
}
