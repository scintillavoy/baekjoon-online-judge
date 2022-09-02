#include <iostream>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  cout << ((A + B) >= 2 * C ? A + B - 2 * C : A + B);
  return 0;
}
