#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int x, y;
  cin >> x >> y;
  cout << (x <= y ? y - x : x + y);
  return 0;
}
