#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  vector<int> scores(6);
  int sum = 0;
  for (int i = 0; i < scores.size(); ++i) {
    cin >> scores[i];
    sum += scores[i];
  }
  sum -= *min_element(scores.cbegin(), scores.cbegin() + 4);
  sum -= *min_element(scores.cbegin() + 4, scores.cend());
  cout << sum;
  return 0;
}
