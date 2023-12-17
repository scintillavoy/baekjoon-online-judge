#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<int> vec(1'000'000 + 1);
  for (int i = 0; i < N; ++i) {
    int start, end;
    cin >> start >> end;
    ++vec[start];
    --vec[end];
  }
  for (int i = 1; i < vec.size(); ++i) {
    vec[i] += vec[i - 1];
  }
  int left = 0, right = 1, sum = vec[0];
  while (true) {
    if (sum == K) {
      cout << left << ' ' << right;
      return 0;
    }
    if (sum < K) {
      if (right == vec.size()) {
        break;
      }
      sum += vec[right];
      ++right;
    } else {
      sum -= vec[left];
      ++left;
    }
  }
  cout << "0 0";
  return 0;
}
