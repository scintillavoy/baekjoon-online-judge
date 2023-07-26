#include <iostream>
using namespace std;

int main() {
  int a = 2000;
  for (int i = 0; i < 3; ++i) {
    int price;
    cin >> price;
    if (price < a) {
      a = price;
    }
  }
  int b = 2000;
  for (int i = 0; i < 2; ++i) {
    int price;
    cin >> price;
    if (price < b) {
      b = price;
    }
  }
  cout << a + b - 50;
  return 0;
}
