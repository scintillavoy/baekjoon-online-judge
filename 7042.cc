#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int W, L;
vector<vector<int>> heights;
vector<vector<int>> scc_id;
int current_scc_id = 0;
vector<vector<int>> start_time;
int current_time = 0;
vector<vector<int>> lowlink;
stack<pair<int, int>> s;

void dfs(pair<int, int> curr) {
  auto [x, y] = curr;
  start_time[x][y] = ++current_time;
  lowlink[x][y] = start_time[x][y];
  s.push(curr);
  for (int i = 0; i < 4; ++i) {
    int x2 = x + dx[i];
    int y2 = y + dy[i];
    if (x2 < 0 || x2 >= L || y2 < 0 || y2 >= W ||
        heights[x][y] < heights[x2][y2]) {
      continue;
    }
    if (start_time[x2][y2] == 0) {
      dfs({x2, y2});
      lowlink[x][y] = min(lowlink[x][y], lowlink[x2][y2]);
    } else if (scc_id[x2][y2] == 0) {
      lowlink[x][y] = min(lowlink[x][y], start_time[x2][y2]);
    }
  }
  if (lowlink[x][y] == start_time[x][y]) {
    ++current_scc_id;
    while (true) {
      pair<int, int> t = s.top();
      s.pop();
      scc_id[t.first][t.second] = current_scc_id;
      if (t == curr) {
        break;
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> W >> L;
  heights = vector<vector<int>>(L, vector<int>(W));
  scc_id = vector<vector<int>>(L, vector<int>(W));
  start_time = vector<vector<int>>(L, vector<int>(W));
  lowlink = vector<vector<int>>(L, vector<int>(W));
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> heights[i][j];
    }
  }
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < W; ++j) {
      if (start_time[i][j] == 0) {
        dfs({i, j});
      }
    }
  }
  if (current_scc_id == 1) {
    cout << 0;
    return 0;
  }
  vector<int> in_degree(current_scc_id + 1);
  vector<int> out_degree(current_scc_id + 1);
  for (int x = 0; x < L; ++x) {
    for (int y = 0; y < W; ++y) {
      for (int k = 0; k < 4; ++k) {
        int x2 = x + dx[k];
        int y2 = y + dy[k];
        if (x2 < 0 || x2 >= L || y2 < 0 || y2 >= W ||
            heights[x][y] < heights[x2][y2] || scc_id[x][y] == scc_id[x2][y2]) {
          continue;
        }
        ++out_degree[scc_id[x][y]];
        ++in_degree[scc_id[x2][y2]];
      }
    }
  }
  int no_inward_count = 0;
  int no_outward_count = 0;
  for (int i = 1; i < current_scc_id + 1; ++i) {
    if (in_degree[i] == 0) {
      ++no_inward_count;
    }
    if (out_degree[i] == 0) {
      ++no_outward_count;
    }
  }
  cout << max(no_inward_count, no_outward_count);
  return 0;
}
