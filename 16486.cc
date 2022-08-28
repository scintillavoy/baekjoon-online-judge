#include <iostream>
using namespace std;

#define pi 3.141592

int main() {
  int d1, d2;
  cin >> d1 >> d2;
  cout.precision(6);
  cout << fixed << d1 * 2 + 2 * pi * d2;
  return 0;
}
