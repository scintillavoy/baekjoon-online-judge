#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  double answer = 0.0, current = 1.0;
  for (int i = 0; i < N; ++i) {
    double num;
    cin >> num;
    current *= num;
    answer = max(answer, current);
    current = max(current, 1.0);
  }
  cout.precision(3);
  cout << fixed << answer;
  return 0;
}
