#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> vec(N);
  for (auto &x : vec) {
    cin >> x;
  }
  sort(vec.begin(), vec.end(), [](const string &a, const string &b) {
    if (a.size() != b.size()) {
      return a.size() < b.size();
    }
    int sum_a = 0, sum_b = 0;
    for (const auto &x : a) {
      if (isdigit(x)) {
        sum_a += x - '0';
      }
    }
    for (const auto &x : b) {
      if (isdigit(x)) {
        sum_b += x - '0';
      }
    }
    if (sum_a != sum_b) {
      return sum_a < sum_b;
    }
    return a < b;
  });
  for (const auto &x : vec) {
    cout << x << '\n';
  }
  return 0;
}
