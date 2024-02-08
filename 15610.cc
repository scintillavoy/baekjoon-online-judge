#include <cmath>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  long long a;
  cin >> a;
  cout.precision(6);
  cout << fixed << sqrt(a) * 4;
  return 0;
}
