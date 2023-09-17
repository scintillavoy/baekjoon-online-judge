#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  vector<bool> sieve(10000, true);
  sieve[0] = false;
  sieve[1] = false;
  for (int i = 2; i <= sqrt(10000); ++i) {
    if (!sieve[i]) {
      continue;
    }
    for (int j = i * i; j <= 10000; j += i) {
      sieve[j] = false;
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int A, B;
    cin >> A >> B;
    vector<bool> is_visited(10000, false);
    queue<pair<int, int>> q;
    is_visited[A] = true;
    q.push({0, A});
    while (!q.empty()) {
      auto [curr_distance, curr] = q.front();
      q.pop();
      if (curr == B) {
        cout << curr_distance;
        break;
      }
      for (int i = 0; i < 4; ++i) {
        string next_str = to_string(curr);
        for (int j = 0; j < 10; ++j) {
          if (i == 0 && j == 0) {
            continue;
          }
          next_str[i] = '0' + j;
          int next = stoi(next_str);
          if (is_visited[next] || !sieve[next]) {
            continue;
          }
          is_visited[next] = true;
          q.push({curr_distance + 1, next});
        }
      }
    }
    if (!is_visited[B]) {
      cout << "Impossible";
    }
    cout << '\n';
  }
  return 0;
}
