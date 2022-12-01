#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int K;
  cin >> K;
  for (int i = 1; i <= K; ++i) {
    int c, n;
    cin >> c >> n;

    vector<int> m(c, 0);
    for (auto &x : m) {
      cin >> x;
    }

    while (n--) {
      int b;
      cin >> b;
      --m[b - 1];
    }

    cout << "Data Set " << i << ":\n"
         << *max_element(m.cbegin(), m.cend()) << "\n\n";
  }
  return 0;
}
