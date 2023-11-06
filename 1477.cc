#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M, L;
  cin >> N >> M >> L;
  vector<int> positions(N);
  for (int i = 0; i < N; ++i) {
    cin >> positions[i];
  }
  positions.push_back(0);
  positions.push_back(L);
  sort(positions.begin(), positions.end());
  vector<int> distances;
  for (int i = 1; i < positions.size(); ++i) {
    distances.push_back(positions[i] - positions[i - 1]);
  }
  int left = 1, right = *max_element(distances.cbegin(), distances.cend());
  while (left <= right) {
    int mid = (left + right) / 2;
    int count = 0;
    for (int i = 0; i < distances.size(); ++i) {
      count += (distances[i] - 1) / mid;
    }
    if (count <= M) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << left;
  return 0;
}
