#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  cout << 1 / (1 + pow(10, (double)(B - A) / 400));
  return 0;
}
