#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> scores(N);
  for (auto &x : scores) {
    cin >> x;
  }

  int M = *max_element(scores.cbegin(), scores.cend());
  double average = 0;
  for (const auto &x : scores) {
    average += (double)x / M * 100;
  }
  average /= scores.size();
  cout.precision(2);
  cout << fixed << average;
  return 0;
}
