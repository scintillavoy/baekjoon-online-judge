#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, W, H, L;
  cin >> N >> W >> H >> L;
  cout << min(N, (W / L) * (H / L));
  return 0;
}
