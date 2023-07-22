#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int num_of_winner = 0;
  int score_of_winner = 0;
  for (int i = 1; i <= 5; ++i) {
    vector<int> scores(4);
    for (auto &x : scores) {
      cin >> x;
    }
    int sum = accumulate(scores.cbegin(), scores.cend(), 0);
    if (sum > score_of_winner) {
      num_of_winner = i;
      score_of_winner = sum;
    }
  }
  cout << num_of_winner << ' ' << score_of_winner;
  return 0;
}
