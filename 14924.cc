#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int S, T, D;
  cin >> S >> T >> D;
  cout << T * D / (S * 2);
  return 0;
}
