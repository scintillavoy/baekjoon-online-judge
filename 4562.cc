#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    cout << (x >= y ? "MMM" : "NO") << " BRAINS\n";
  }
  return 0;
}
