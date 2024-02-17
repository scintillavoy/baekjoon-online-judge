#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, d, k, c;
  cin >> N >> d >> k >> c;
  vector<int> belt(N);
  for (int i = 0; i < N; ++i) {
    cin >> belt[i];
  }
  vector<int> sushi(d + 1);
  int count = 0;
  for (int i = 0; i < k; ++i) {
    ++sushi[belt[i]];
    if (sushi[belt[i]] == 1) {
      ++count;
    }
  }
  int max_count = count + (sushi[c] == 0 ? 1 : 0);
  for (int i = 0; i < N - 1; ++i) {
    --sushi[belt[i]];
    if (sushi[belt[i]] == 0) {
      --count;
    }
    ++sushi[belt[(i + k) % N]];
    if (sushi[belt[(i + k) % N]] == 1) {
      ++count;
    }
    max_count = max(max_count, count + (sushi[c] == 0 ? 1 : 0));
  }
  cout << max_count;
  return 0;
}
