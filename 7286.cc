#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int diff[1001] = {0};
    while (n--) {
      char alphabet;
      int a, b;
      cin >> alphabet >> a >> b;
      ++diff[a];
      --diff[b];
    }
    int num_of_LEDs_on = 0;
    for (const auto &x : diff) {
      num_of_LEDs_on += x;
      if (num_of_LEDs_on > 0) {
        cout << char('A' + num_of_LEDs_on - 1);
      }
    }
    cout << '\n';
  }
  return 0;
}
