#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int X, Y, Z;
  cin >> X >> Y >> Z;
  cout << (X + Y <= Z ? 1 : 0);
  return 0;
}
