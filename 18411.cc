#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int A, B, C;
  cin >> A >> B >> C;
  cout << A + B + C - min({A, B, C});
  return 0;
}
