#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> statements(n);
  for (auto &x : statements) {
    cin >> x.first >> x.second;
  }
  int num_of_truths = n;
  for (num_of_truths = n; num_of_truths >= 0; --num_of_truths) {
    int num_of_lies = 0;
    for (const auto &x : statements) {
      if (!(x.first <= num_of_truths && num_of_truths <= x.second)) {
        ++num_of_lies;
        if (num_of_lies + num_of_truths > n) {
          break;
        }
      }
    }
    if (num_of_lies + num_of_truths == n) {
      break;
    }
  }
  cout << num_of_truths;
  return 0;
}
