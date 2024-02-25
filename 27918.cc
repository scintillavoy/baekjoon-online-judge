#include <cmath>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  int D = 0, P = 0;
  for (int i = 0; i < N; ++i) {
    char c;
    cin >> c;
    if (c == 'D') {
      ++D;
    } else if (c == 'P') {
      ++P;
    }
    if (abs(D - P) >= 2) {
      for (++i; i < N; ++i) {
        cin >> c;
      }
      break;
    }
  }
  cout << D << ':' << P;
  return 0;
}
