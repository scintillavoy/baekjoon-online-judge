#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int count = 0;
  for (int i = 0; i < 6; ++i) {
    char c;
    cin >> c;
    if (c == 'W') {
      ++count;
    }
  }
  if (count >= 5) {
    cout << 1;
  } else if (count >= 3) {
    cout << 2;
  } else if (count >= 1) {
    cout << 3;
  } else {
    cout << -1;
  }
  return 0;
}
