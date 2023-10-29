#include <iostream>
using namespace std;

int count_fives(int number) {
  int count = 0;
  while (number >= 5) {
    count += number / 5;
    number /= 5;
  }
  return count;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int M;
  cin >> M;
  int answer = -1;
  int left = 1, right = 5 * 100'000'000;
  while (left <= right) {
    int mid = (left + right) / 2;
    int count = count_fives(mid);
    if (count < M) {
      left = mid + 1;
    } else {
      if (count == M) {
        answer = mid;
      }
      right = mid - 1;
    }
  }
  cout << answer;
  return 0;
}
