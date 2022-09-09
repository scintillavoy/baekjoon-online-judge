#include <iostream>
using namespace std;

int main() {
  int L, P;
  cin >> L >> P;
  for (int i = 0; i < 5; ++i) {
    int participants;
    cin >> participants;
    cout << participants - L * P << ' ';
  }
  return 0;
}
