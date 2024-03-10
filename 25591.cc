#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n1, n2;
  cin >> n1 >> n2;
  int a = 100 - n1;
  int b = 100 - n2;
  int c = 100 - (a + b);
  int d = a * b;
  int q = d / 100;
  int r = d % 100;
  cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << q << ' ' << r << '\n';
  cout << c + q << ' ' << r;
  return 0;
}
