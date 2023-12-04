#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  cout << min(A + D, B + C);
  return 0;
}
