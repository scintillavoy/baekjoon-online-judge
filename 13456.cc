#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> v(n), u(n);
    for (auto &x : v) {
      cin >> x;
    }
    for (auto &x : u) {
      cin >> x;
    }
    int hamming_distance = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i] != u[i]) ++hamming_distance;
    }
    cout << hamming_distance << '\n';
  }
  return 0;
}
