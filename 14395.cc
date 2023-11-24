#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int s, t;
  cin >> s >> t;
  if (s == t) {
    cout << 0;
    return 0;
  }
  unordered_set<int> visited;
  queue<pair<int, string>> q;
  visited.insert(s);
  q.push({s, ""});
  while (!q.empty()) {
    auto [curr, operations] = q.front();
    q.pop();
    if (curr == t) {
      cout << operations;
      return 0;
    }
    long long next = (long long)curr * curr;
    if (next <= 1e9 && visited.count(next) == 0) {
      visited.insert(next);
      q.push({next, operations + '*'});
    }
    next = (long long)curr + curr;
    if (next <= 1e9 && visited.count(next) == 0) {
      visited.insert(next);
      q.push({next, operations + '+'});
    }
    next = 1;
    if (next <= 1e9 && visited.count(next) == 0) {
      visited.insert(next);
      q.push({next, operations + '/'});
    }
  }
  cout << -1;
  return 0;
}
