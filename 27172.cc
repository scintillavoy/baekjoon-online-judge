#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#define MAX 1'000'000

int main() {
  int N;
  cin >> N;
  vector<int> numbers(N);
  unordered_map<int, int> scores;
  for (auto &number : numbers) {
    cin >> number;
    scores[number] = 0;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = numbers[i] * 2; j <= MAX; j += numbers[i]) {
      if (scores.count(j) == 0) {
        continue;
      }
      ++scores[numbers[i]];
      --scores[j];
    }
  }
  for (int i = 0; i < N; ++i) {
    cout << scores[numbers[i]] << ' ';
  }
  return 0;
}
