#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  vector<int> p(4);
  for (int i = 0; i < p.size(); ++i) {
    cin >> p[i];
  }
  int x, y, r;
  cin >> x >> y >> r;
  for (int i = 0; i < p.size(); ++i) {
    if (p[i] == x) {
      cout << i + 1;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
