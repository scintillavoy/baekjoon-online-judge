#include <iostream>
using namespace std;

int main() {
  int W, H;
  cin >> W >> H;
  cout.precision(1);
  cout << fixed << (double)W * H / 2 << '\n';
  return 0;
}
