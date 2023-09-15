#include <iostream>
using namespace std;

int main() {
  int T, S;
  cin >> T >> S;
  cout << ((S == 1 || !(12 <= T && T <= 16)) ? 280 : 320);
  return 0;
}
