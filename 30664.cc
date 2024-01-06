#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  while (true) {
    string n;
    cin >> n;
    if (n == "0") {
      break;
    }
    int sum = 0;
    for (auto it = n.cbegin(); it != n.cend(); ++it) {
      sum = (sum * 10 + *it - '0') % 42;
    }
    if (sum == 0) {
      cout << "PREMIADO";
    } else {
      cout << "TENTE NOVAMENTE";
    }
    cout << '\n';
  }
  return 0;
}
