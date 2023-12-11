#include <iostream>
#include <utility>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int A, B, C;
  cin >> A >> B >> C;
  if (B < C) {
    swap(B, C);
  }
  cout << int(double(A) * B / C);
  return 0;
}
