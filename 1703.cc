#include <iostream>
using namespace std;

int main() {
  while (true) {
    int a;
    cin >> a;
    if (a == 0) break;
    int result = 1;
    for (int i = 0; i < a; ++i) {
      int splitting_factor, pruning_count;
      cin >> splitting_factor >> pruning_count;
      result = result * splitting_factor - pruning_count;
    }
    cout << result << '\n';
  }
  return 0;
}
