#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  cout << (N / 10000 == 555 ? "YES" : "NO");
  return 0;
}
