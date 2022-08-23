#include <iostream>
using namespace std;

int main() {
  int W, N;
  cin >> W >> N;
  int volume = 0;
  while (N--) {
    int w, l;
    cin >> w >> l;
    volume += w * l;
  }
  cout << volume / W;
  return 0;
}
