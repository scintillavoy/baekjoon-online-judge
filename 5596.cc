#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < 4; ++i) {
    int score;
    cin >> score;
    sum1 += score;
  }
  for (int i = 0; i < 4; ++i) {
    int score;
    cin >> score;
    sum2 += score;
  }
  cout << max(sum1, sum2);
  return 0;
}
