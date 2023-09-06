#include <iostream>
using namespace std;

int main() {
  for (int i = 1, N; cin >> N; ++i) {
    if (N == 0) break;
    for (int j = 0; j < N; ++j) {
      int num;
      cin >> num;
    }
    cout << "Case " << i << ": Sorting... done!\n";
  }
  return 0;
}
