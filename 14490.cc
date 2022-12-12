#include <iostream>
#include <numeric>
using namespace std;

int main() {
  int n, m;
  char delimiter;
  cin >> n >> delimiter >> m;
  int g = gcd(n, m);
  cout << n / g << ':' << m / g;
  return 0;
}
