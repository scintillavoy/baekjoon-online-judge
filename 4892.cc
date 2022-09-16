#include <iostream>
using namespace std;

int main() {
  for (int i = 1; true; ++i) {
    int n0;
    cin >> n0;
    if (n0 == 0) break;
    cout << i << ". " << (n0 % 2 == 1 ? "odd" : "even") << ' ';
    cout << (n0 * 3 + 1) / 6 << '\n';
  }
  return 0;
}
