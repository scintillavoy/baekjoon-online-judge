#include <iostream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string result;
    cin >> result;
    int score = 0, streak = 0;
    for (const auto &x : result) {
      if (x == 'O') {
        ++streak;
        score += streak;
      } else {
        streak = 0;
      }
    }
    cout << score << '\n';
  }
  return 0;
}
