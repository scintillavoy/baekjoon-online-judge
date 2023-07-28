#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int M;
  cin >> M;
  int S = 0;
  while (M--) {
    string command;
    cin >> command;
    if (command == "add") {
      int x;
      cin >> x;
      S |= (1 << x);
    } else if (command == "remove") {
      int x;
      cin >> x;
      S &= ~(1 << x);
    } else if (command == "check") {
      int x;
      cin >> x;
      cout << ((S & (1 << x)) != 0 ? 1 : 0) << '\n';
    } else if (command == "toggle") {
      int x;
      cin >> x;
      if ((S & (1 << x)) != 0) {
        S &= ~(1 << x);
      } else {
        S |= (1 << x);
      }
    } else if (command == "all") {
      S = (1 << 21) - 1;
    } else if (command == "empty") {
      S = 0;
    }
  }
  return 0;
}
