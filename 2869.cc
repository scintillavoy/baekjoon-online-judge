#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int A, B, V;
  cin >> A >> B >> V;
  V -= A;
  cout << 1 + int(ceil((double)V / (A - B)));
  return 0;
}
