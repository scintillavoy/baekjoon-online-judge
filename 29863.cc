#include <iostream>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  if (A >= 20) {
    A -= 24;
  }
  cout << B - A;
  return 0;
}
