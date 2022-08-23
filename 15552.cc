#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int T, A, B;
  for (cin >> T; T > 0; --T) {
    cin >> A >> B;
    cout << A + B << '\n';
  }
  return 0;
}
