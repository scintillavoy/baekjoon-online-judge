#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    long long lt, wt, le, we;
    cin >> lt >> wt >> le >> we;
    long long t = lt * wt, e = le * we;
    if (t > e) {
      cout << "TelecomParisTech";
    } else if (t < e) {
      cout << "Eurecom";
    } else {
      cout << "Tie";
    }
    cout << '\n';
  }
  return 0;
}
