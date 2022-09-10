#include <iostream>
#include <limits>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int N;
  cin >> N;
  int max_score = numeric_limits<int>::min();
  while (N--) {
    int score = 0;
    for (int i = 0; i < 3; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      score += a * A + b * B + c * C;
    }
    if (score > max_score) {
      max_score = score;
    }
  }
  cout << max_score;
  return 0;
}
