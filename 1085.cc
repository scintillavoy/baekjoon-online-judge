#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int x, y, w, h;
  cin >> x >> y >> w >> h;
  cout << min({x, y, w - x, h - y});
  return 0;
}
