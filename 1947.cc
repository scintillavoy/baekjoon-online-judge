#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  if (N == 1) {
    cout << 0;
    return 0;
  }
  long long prev = 0, curr = 1;
  for (int i = 3; i <= N; ++i) {
    long long next = (i - 1) * (curr + prev) % 1'000'000'000;
    prev = curr;
    curr = next;
  }
  cout << curr;
  return 0;
}
