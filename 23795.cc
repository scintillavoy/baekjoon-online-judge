#include <iostream>
using namespace std;

int main() {
  int sum = 0;
  while (true) {
    int bet;
    cin >> bet;
    if (bet == -1) {
      break;
    }
    sum += bet;
  }
  cout << sum;
  return 0;
}
