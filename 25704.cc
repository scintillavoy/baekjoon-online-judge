#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, P;
  cin >> N >> P;
  int min_price = P;
  if (N >= 5) {
    min_price = min(min_price, P - 500);
  }
  if (N >= 10) {
    min_price = min(min_price, int(P * 0.9));
  }
  if (N >= 15) {
    min_price = min(min_price, P - 2000);
  }
  if (N >= 20) {
    min_price = min(min_price, int(P * 0.75));
  }
  min_price = max(min_price, 0);
  cout << min_price;
  return 0;
}
