#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  string emoji;
  cin >> emoji;
  int difficulty = emoji.size();
  for (const auto &x : emoji) {
    if (x == ':') {
      ++difficulty;
    } else if (x == '_') {
      difficulty += 5;
    }
  }
  cout << difficulty;
  return 0;
}
