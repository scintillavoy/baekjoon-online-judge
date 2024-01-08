#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  if (M <= 2) {
    cout << "NEWBIE!";
  } else if (M <= N) {
    cout << "OLDBIE!";
  } else {
    cout << "TLE!";
  }
  return 0;
}
