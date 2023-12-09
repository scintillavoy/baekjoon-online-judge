#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<string, int>> vec;
  for (int i = 0; i < N; ++i) {
    string start, end;
    cin >> start >> end;
    vec.push_back({start, 1});
    vec.push_back({end, -1});
  }
  sort(vec.begin(), vec.end(),
       [](const pair<string, int> a, const pair<string, int> b) {
         if (a.first != b.first) {
           return a.first < b.first;
         }
         return a.second > b.second;
       });
  int max_count = 0;
  int count = 0;
  string answer;
  for (int i = 0; i < vec.size(); ++i) {
    count += vec[i].second;
    if (max_count < count) {
      max_count = count;
      answer = vec[i].first;
    }
  }
  cout << answer;
  return 0;
}
