#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> sides(3);
  while (true) {
    for (auto &x : sides) {
      cin >> x;
    }
    if (all_of(sides.cbegin(), sides.cend(),
               [](const int &x) { return x == 0; })) {
      break;
    }
    sort(sides.begin(), sides.end());
    cout << (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]
                 ? "right"
                 : "wrong")
         << '\n';
  }
  return 0;
}
