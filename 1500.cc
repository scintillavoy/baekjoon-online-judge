#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int S, K;
  cin >> S >> K;
  if (K <= 0) {
    cout << 0;
    return 0;
  }
  long long product = 1;
  int remainder = S % K;
  for (int i = 0; i < K; ++i) {
    int num = S / K;
    if (remainder > 0) {
      --remainder;
      ++num;
    }
    product *= num;
  }
  cout << product;
  return 0;
}
