#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < 3; ++i) {
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    int h = h2 - h1;
    int m = m2 - m1;
    if (m < 0) {
      --h;
      m += 60;
    }
    int s = s2 - s1;
    if (s < 0) {
      --m;
      s += 60;
      if (m < 0) {
        --h;
        m += 60;
      }
    }
    cout << h << ' ' << m << ' ' << s << '\n';
  }
  return 0;
}
