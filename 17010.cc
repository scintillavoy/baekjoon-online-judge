#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int L;
  cin >> L;
  while (L--) {
    int num;
    char c;
    cin >> num >> c;
    for (int i = 0; i < num; ++i) {
      cout << c;
    }
    cout << '\n';
  }
  return 0;
}
