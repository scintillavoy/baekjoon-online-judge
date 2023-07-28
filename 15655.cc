#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> numbers;
vector<int> sequence;

void solve(int depth, int from) {
  if (depth == M) {
    for (const auto &x : sequence) {
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = from; i < numbers.size(); ++i) {
    sequence[depth] = numbers[i];
    solve(depth + 1, i + 1);
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
  solve(0, 0);
  return 0;
}
