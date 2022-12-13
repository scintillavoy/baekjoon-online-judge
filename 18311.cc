#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<int> distances(N);
  for (auto &x : distances) {
    cin >> x;
  }
  for (int i = 0; i < N; ++i) {
    if (K < distances[i]) {
      cout << i + 1;
      return 0;
    }
    K -= distances[i];
  }
  for (int i = N - 1; i >= 0; --i) {
    if (K < distances[i]) {
      cout << i + 1;
      return 0;
    }
    K -= distances[i];
  }
  return 0;
}
