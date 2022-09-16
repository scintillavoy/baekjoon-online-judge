#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int A, B;
    char delimiter;
    cin >> A >> delimiter >> B;
    cout << A + B << '\n';
  }
  return 0;
}
