#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    if ((N + 1) % (N % 100) == 0) {
      cout << "Good";
    } else {
      cout << "Bye";
    }
    cout << '\n';
  }
  return 0;
}
