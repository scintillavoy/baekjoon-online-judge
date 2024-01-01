#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int D, H, M;
  cin >> D >> H >> M;
  int total = max(D - 11, 0) * 24 * 60 + (H - 11) * 60 + M - 11;
  cout << (total >= 0 ? total : -1);
  return 0;
}
