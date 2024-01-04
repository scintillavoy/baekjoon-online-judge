#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int Ca, Ba, Pa;
  cin >> Ca >> Ba >> Pa;
  int Cr, Br, Pr;
  cin >> Cr >> Br >> Pr;
  cout << max(Cr - Ca, 0) + max(Br - Ba, 0) + max(Pr - Pa, 0);
  return 0;
}
