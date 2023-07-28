#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> numbers;
vector<bool> is_visited;
vector<int> sequence;

void solve(int depth, int from) {
  if (depth == M) {
    for (const auto &x : sequence) {
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }
  int prev = 0;
  for (int i = from; i < numbers.size(); ++i) {
    if (!is_visited[i] && prev != numbers[i]) {
      prev = numbers[i];
      is_visited[i] = true;
      sequence[depth] = numbers[i];
      solve(depth + 1, i + 1);
      is_visited[i] = false;
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
  is_visited = vector<bool>(N, false);
  sequence = vector<int>(M);
  solve(0, 0);
  return 0;
}
