#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  string founder;
  cin >> founder;
  unordered_map<string, vector<string>> graph;
  unordered_map<string, int> in_degree;
  for (int i = 0; i < N; ++i) {
    string child, parent1, parent2;
    cin >> child >> parent1 >> parent2;
    graph[parent1].push_back(child);
    graph[parent2].push_back(child);
    if (in_degree.count(parent1) == 0) {
      in_degree[parent1] = 0;
    }
    if (in_degree.count(parent2) == 0) {
      in_degree[parent2] = 0;
    }
    in_degree[child] += 2;
  }
  unordered_map<string, double> score;
  score[founder] = 1.0;
  queue<string> q;
  for (const auto &x : in_degree) {
    if (x.second != 0) continue;
    q.push(x.first);
  }
  while (!q.empty()) {
    string curr = q.front();
    q.pop();
    for (const auto &adj : graph[curr]) {
      score[adj] += score[curr];
      --in_degree[adj];
      if (in_degree[adj] == 0) {
        score[adj] /= 2;
        q.push(adj);
      }
    }
  }
  string successor;
  double max_score = -1.0;
  for (int i = 0; i < M; ++i) {
    string name;
    cin >> name;
    if (score[name] > max_score) {
      successor = name;
      max_score = score[name];
    }
  }
  cout << successor;
  return 0;
}
