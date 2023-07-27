#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int M;
  cin >> M;
  long long sum = 0;
  int xor_value = 0;
  while (M--) {
    int type;
    cin >> type;
    int x;
    switch (type) {
      case 1:
        cin >> x;
        sum += x;
        xor_value ^= x;
        break;
      case 2:
        cin >> x;
        sum -= x;
        xor_value ^= x;
        break;
      case 3:
        cout << sum << '\n';
        break;
      case 4:
        cout << xor_value << '\n';
        break;
    }
  }
  return 0;
}
