#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int D, H, W;
  cin >> D >> H >> W;
  double proportional_factor = sqrt(H * H + W * W);
  int height = D * H / proportional_factor;
  int width = D * W / proportional_factor;
  cout << height << ' ' << width;
  return 0;
}
