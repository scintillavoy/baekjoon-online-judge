#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    double d, f, p;
    cin >> d >> f >> p;
    cout.precision(2);
    cout << fixed << '$' << d * f * p << '\n';
  }
  return 0;
}
