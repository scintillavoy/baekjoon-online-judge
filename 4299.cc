#include <iostream>
#include <utility>
using namespace std;

int main() {
  int sum, difference;
  cin >> sum >> difference;
  int score_a = (sum + difference) / 2;
  int score_b = (sum - difference) / 2;
  if ((sum + difference) % 2 != 0 || (sum - difference) % 2 != 0 ||
      score_a < 0 || score_b < 0) {
    cout << -1;
    return 0;
  }
  if (score_a < score_b) {
    swap(score_a, score_b);
  }
  cout << score_a << ' ' << score_b;
  return 0;
}
