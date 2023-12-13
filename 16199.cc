#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int y, m, d;
  cin >> y >> m >> d;
  int y2, m2, d2;
  cin >> y2 >> m2 >> d2;
  int age = y2 - y;
  if (m2 < m || (m2 == m && d2 < d)) {
    --age;
  }
  cout << age << '\n';
  cout << y2 - y + 1 << '\n';
  cout << y2 - y;
  return 0;
}
