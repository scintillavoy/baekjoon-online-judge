#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  while (true) {
    int M, F;
    cin >> M >> F;
    if (M == 0 && F == 0) {
      break;
    }
    cout << M + F << '\n';
  }
  return 0;
}
