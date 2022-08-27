#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, string>> users(N);
  for (auto &x : users) {
    cin >> x.first >> x.second;
  }
  stable_sort(users.begin(), users.end(),
              [](const pair<int, string> &a, const pair<int, string> &b) {
                return a.first < b.first;
              });
  for (const auto &x : users) {
    cout << x.first << ' ' << x.second << '\n';
  }
  return 0;
}
