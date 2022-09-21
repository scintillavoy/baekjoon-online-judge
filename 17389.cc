#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int bonus_score = 0;
  int sum = 0;
  for (int i = 1; i <= N; ++i) {
    char s;
    cin >> s;
    if (s == 'O') {
      sum += i + bonus_score;
      ++bonus_score;
    } else if (s == 'X') {
      bonus_score = 0;
    }
  }
  cout << sum;
  return 0;
}
