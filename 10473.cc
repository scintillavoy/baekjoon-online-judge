#include <cmath>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

double distance(pair<double, double> x, pair<double, double> y) {
  return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  vector<pair<double, double>> positions;
  for (int i = 0; i < 2; ++i) {
    double X, Y;
    cin >> X >> Y;
    positions.push_back({X, Y});
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    double X, Y;
    cin >> X >> Y;
    positions.push_back({X, Y});
  }
  vector<vector<pair<double, int>>> graph(positions.size());
  for (int i = 0; i < positions.size(); ++i) {
    for (int j = i + 1; j < positions.size(); ++j) {
      double weight = distance(positions[i], positions[j]) / 5;
      graph[i].push_back({weight, j});
      graph[j].push_back({weight, i});
    }
  }
  for (int i = 2; i < positions.size(); ++i) {
    for (int j = 0; j < positions.size(); ++j) {
      if (i == j) {
        continue;
      }
      double weight = abs(distance(positions[i], positions[j]) - 50) / 5 + 2;
      graph[i].push_back({weight, j});
    }
  }
  vector<double> distance_(positions.size(), numeric_limits<double>::max());
  priority_queue<pair<double, int>, vector<pair<double, int>>,
                 greater<pair<double, int>>>
      pq;
  distance_[0] = 0.0;
  pq.push({0.0, 0});
  while (!pq.empty()) {
    auto [curr_distance, curr] = pq.top();
    pq.pop();
    if (distance_[curr] < curr_distance) {
      continue;
    }
    for (const auto& [adj_weight, adj] : graph[curr]) {
      if (distance_[adj] > distance_[curr] + adj_weight) {
        distance_[adj] = distance_[curr] + adj_weight;
        pq.push({distance_[adj], adj});
      }
    }
  }
  cout << distance_[1];
  return 0;
}
