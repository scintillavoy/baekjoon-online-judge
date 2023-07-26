#include <iostream>
using namespace std;

int main() {
  long long A, B;
  cin >> A >> B;
  cout << B * (B + 1) / 2 * (A - 2) + B + 1;
  return 0;
}
