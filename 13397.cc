#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int> numbers(N);
  for (int i = 0; i < numbers.size(); ++i) {
    cin >> numbers[i];
  }
  int left = 0, right = 10'000;
  while (left <= right) {
    int mid = (left + right) / 2;
    int count = 1;
    int min_number = numbers[0];
    int max_number = numbers[0];
    for (int i = 1; i < numbers.size(); ++i) {
      min_number = min(min_number, numbers[i]);
      max_number = max(max_number, numbers[i]);
      if (max_number - min_number > mid) {
        ++count;
        min_number = numbers[i];
        max_number = numbers[i];
      }
    }
    if (count <= M) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << left;
  return 0;
}
