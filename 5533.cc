#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> numbers(N, vector<int>(3));
  vector<unordered_map<int, int>> check(3);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> numbers[i][j];
      ++check[j][numbers[i][j]];
    }
  }
  for (int i = 0; i < N; ++i) {
    int score = 0;
    for (int j = 0; j < 3; ++j) {
      if (check[j][numbers[i][j]] == 1) {
        score += numbers[i][j];
      }
    }
    cout << score << '\n';
  }
  return 0;
}
