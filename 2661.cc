#include <iostream>
#include <vector>
using namespace std;

vector<int> sequence;

bool is_identical(int a, int b, int len) {
  for (int i = 0; i < len; ++i) {
    if (sequence[a + i] != sequence[b + i]) {
      return false;
    }
  }
  return true;
}

bool backtrack(int count) {
  if (count == 0) {
    for (const auto &x : sequence) {
      cout << x;
    }
    return true;
  }
  for (int i = 1; i <= 3; ++i) {
    sequence.push_back(i);
    bool ok = true;
    int size = sequence.size();
    for (int j = 1; j <= size / 2; ++j) {
      if (is_identical(size - j, size - j * 2, j)) {
        ok = false;
        break;
      }
    }
    if (ok && backtrack(count - 1)) {
      return true;
    }
    sequence.pop_back();
  }
  return false;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  backtrack(N);
  return 0;
}
