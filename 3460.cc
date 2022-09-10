#include <bitset>
#include <iostream>
#include <limits>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int n;
    cin >> n;
    bitset<sizeof(int) * numeric_limits<unsigned char>::digits> bs(n);
    for (int i = 0; i < bs.size(); ++i) {
      if (bs.test(i)) {
        cout << i << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}
