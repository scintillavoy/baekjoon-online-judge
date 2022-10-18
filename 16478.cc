#include <iostream>
using namespace std;

int main() {
  int p_ab, p_bc, p_cd;
  cin >> p_ab >> p_bc >> p_cd;
  cout.precision(6);
  cout << fixed << (double)p_ab * p_cd / p_bc;
  return 0;
}
