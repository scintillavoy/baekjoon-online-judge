#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  for (auto &x : X) {
    cin >> x;
  }
  int answer_left = 0, answer_right = N - 1;
  int min_abs = abs(X[answer_left] + X[answer_right]);
  int left = 0, right = N - 1;
  while (left < right) {
    int sum = X[left] + X[right];
    if (abs(sum) < min_abs) {
      min_abs = abs(sum);
      answer_left = left, answer_right = right;
    }
    if (sum <= 0) {
      ++left;
    } else {
      --right;
    }
  }
  cout << X[answer_left] << ' ' << X[answer_right];
  return 0;
}
