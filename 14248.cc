#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> vec[i];
  }
  int s;
  cin >> s;
  vector<bool> is_visited(n + 1, false);
  int count = 0;
  queue<int> bfs_queue;
  is_visited[s] = true;
  ++count;
  bfs_queue.push(s);
  while (!bfs_queue.empty()) {
    int current = bfs_queue.front();
    bfs_queue.pop();
    int right = current + vec[current];
    if (right <= n && !is_visited[right]) {
      is_visited[right] = true;
      ++count;
      bfs_queue.push(right);
    }
    int left = current - vec[current];
    if (left >= 1 && !is_visited[left]) {
      is_visited[left] = true;
      ++count;
      bfs_queue.push(left);
    }
  }
  cout << count;
  return 0;
}
