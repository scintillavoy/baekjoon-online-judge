#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> numbers;
vector<int> sequence;

void solve(int depth) {
  if (depth == M) {
    for (const auto &x : sequence) {
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = 0; i < numbers.size(); ++i) {
    if (i == 0 || numbers[i - 1] != numbers[i]) {
      sequence[depth] = numbers[i];
      solve(depth + 1);
    }
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    int number;
    cin >> number;
    numbers.push_back(number);
  }
  sort(numbers.begin(), numbers.end());
  sequence = vector<int>(M);
  solve(0);
  return 0;
}
