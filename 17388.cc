#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int S, K, H;
  cin >> S >> K >> H;
  if (S + K + H >= 100) {
    cout << "OK";
  } else {
    int minimum = min({S, K, H});
    if (minimum == S) {
      cout << "Soongsil";
    } else if (minimum == K) {
      cout << "Korea";
    } else {
      cout << "Hanyang";
    }
  }
  return 0;
}
