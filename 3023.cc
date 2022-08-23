#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int R, C;
  cin >> R >> C;
  vector<string> card;
  for (int r = 0; r < R; ++r) {
    string line;
    cin >> line;
    card.push_back(line);
    reverse(line.begin(), line.end());
    card.back() += line;
  }

  for (int i = card.size() - 1; i >= 0; --i) {
    card.push_back(card[i]);
  }

  int A, B;
  cin >> A >> B;
  card[A - 1][B - 1] ^= '#' ^ '.';

  for (auto &x : card) {
    cout << x << endl;
  }
  return 0;
}
