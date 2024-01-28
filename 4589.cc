#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  cout << "Gnomes:\n";
  for (int i = 0; i < N; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a < b && b < c) || (a > b && b > c)) {
      cout << "Ordered";
    } else {
      cout << "Unordered";
    }
    cout << '\n';
  }
  return 0;
}
