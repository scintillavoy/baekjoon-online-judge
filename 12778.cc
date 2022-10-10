#include <iostream>
#include <limits>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int M;
    char type;
    cin >> M >> type;
    if (type == 'C') {
      for (int j = 0; j < M; ++j) {
        char c;
        cin >> c;
        cout << c - 'A' + 1 << ' ';
      }
    } else if (type == 'N') {
      for (int j = 0; j < M; ++j) {
        int c;
        cin >> c;
        cout << char(c + 'A' - 1) << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}
