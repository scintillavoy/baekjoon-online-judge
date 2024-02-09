#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int A, B, C;
  cin >> A >> B >> C;
  cout << (A + B + C <= 4 ? 1 : 2);
  return 0;
}
