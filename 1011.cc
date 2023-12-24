#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    int dist = y - x;
    int count = 0;
    int diff = 1;
    bool flag = false;
    while (dist > 0) {
      ++count;
      dist -= diff;
      if (flag) {
        ++diff;
        flag = false;
      } else {
        flag = true;
      }
    }
    cout << count << '\n';
  }
  return 0;
}
