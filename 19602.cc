#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int S, M, L;
  cin >> S >> M >> L;
  cout << (S + 2 * M + 3 * L >= 10 ? "happy" : "sad");
  return 0;
}
