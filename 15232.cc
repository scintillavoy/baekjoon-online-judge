#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int R, C;
  cin >> R >> C;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cout << '*';
    }
    cout << '\n';
  }
  return 0;
}
