#include <iostream>
using namespace std;

int main() {
  int a, b, n, w;
  cin >> a >> b >> n >> w;
  int answer = -1;
  for (int i = 1; i < n; ++i) {
    if (a * i + b * (n - i) == w) {
      if (answer < 0) {
        answer = i;
      } else {
        answer = -1;
        break;
      }
    }
  }
  if (answer < 0) {
    cout << answer;
  } else {
    cout << answer << ' ' << n - answer;
  }
  return 0;
}
