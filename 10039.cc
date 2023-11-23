#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int sum = 0;
  for (int i = 0; i < 5; ++i) {
    int score;
    cin >> score;
    sum += max(score, 40);
  }
  cout << sum / 5;
  return 0;
}
