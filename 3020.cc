#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, H;
  cin >> N >> H;
  vector<int> sums(H + 1);
  for (int i = 0; i < N; i += 2) {
    int height;
    cin >> height;
    ++sums[1];
    --sums[height + 1];
    cin >> height;
    ++sums[H - height + 1];
  }
  int count = 0;
  int min_sum = numeric_limits<int>::max();
  for (int i = 1; i <= H; ++i) {
    sums[i] += sums[i - 1];
    if (sums[i] < min_sum) {
      min_sum = sums[i];
      count = 1;
    } else if (sums[i] == min_sum) {
      ++count;
    }
  }
  cout << min_sum << ' ' << count;
  return 0;
}
