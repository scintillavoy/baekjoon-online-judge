#include <iostream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int R;
    string S;
    cin >> R >> S;
    for (const auto &x : S) {
      for (int i = 0; i < R; ++i) {
        cout << x;
      }
    }
    cout << '\n';
  }
  return 0;
}
