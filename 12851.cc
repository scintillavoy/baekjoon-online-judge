#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100'000

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<int> counts(MAX + 1);
  vector<int> distances(MAX + 1, -1);
  queue<int> q;
  counts[N] = 1;
  distances[N] = 0;
  q.push(N);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int next : {curr - 1, curr + 1, curr * 2}) {
      if (next < 0 || next > MAX) {
        continue;
      }
      if (distances[next] == -1) {
        counts[next] = counts[curr];
        distances[next] = distances[curr] + 1;
        q.push(next);
      } else if (distances[next] == distances[curr] + 1) {
        counts[next] += counts[curr];
      }
    }
  }
  cout << distances[K] << '\n';
  cout << counts[K];
  return 0;
}
