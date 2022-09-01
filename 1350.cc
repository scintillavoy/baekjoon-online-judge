#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> file_sizes(N);
  for (auto &x : file_sizes) {
    cin >> x;
  }
  int cluster_size;
  cin >> cluster_size;
  long long disk_used = 0;
  for (const auto &x : file_sizes) {
    disk_used += (x + cluster_size - 1) / cluster_size * cluster_size;
  }
  cout << disk_used;
  return 0;
}
