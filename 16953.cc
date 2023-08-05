#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  queue<pair<long long, int>> q;
  q.push({A, 1});
  while (!q.empty()) {
    pair<long long, int> current = q.front();
    q.pop();
    if (current.first == B) {
      cout << current.second;
      return 0;
    }
    if (current.first * 2 <= B) {
      q.push({current.first * 2, current.second + 1});
    }
    if (current.first * 10 + 1 <= B) {
      q.push({current.first * 10 + 1, current.second + 1});
    }
  }
  cout << -1;
  return 0;
}
