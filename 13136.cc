#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int R, C, N;
  cin >> R >> C >> N;
  cout << (long long)(R / N + (R % N > 0 ? 1 : 0)) *
              (C / N + (C % N > 0 ? 1 : 0));
  return 0;
}
