#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int A, B;
  cin >> A >> B;
  cout << min(A / 2, B);
  return 0;
}
