#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> numbers(N);
  for (int i = 0; i < numbers.size(); ++i) {
    cin >> numbers[i];
  }
  vector<int> memo;
  memo.push_back(numbers[0]);
  for (int i = 1; i < numbers.size(); ++i) {
    if (memo.back() < numbers[i]) {
      memo.push_back(numbers[i]);
    } else {
      auto it = lower_bound(memo.begin(), memo.end(), numbers[i]);
      *it = numbers[i];
    }
  }
  cout << numbers.size() - memo.size();
  return 0;
}
