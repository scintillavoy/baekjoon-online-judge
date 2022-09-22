#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  cout.precision(2);
  cout << fixed;
  while (N--) {
    double original_price;
    char dot, coupon, payment;
    cin >> original_price >> dot >> coupon >> payment;
    double discounted_price = original_price;
    switch (dot) {
      case 'R':
        discounted_price *= 0.55;
        break;
      case 'G':
        discounted_price *= 0.7;
        break;
      case 'B':
        discounted_price *= 0.8;
        break;
      case 'Y':
        discounted_price *= 0.85;
        break;
      case 'O':
        discounted_price *= 0.9;
        break;
      case 'W':
        discounted_price *= 0.95;
        break;
    }
    if (coupon == 'C') {
      discounted_price *= 0.95;
    }
    if (payment == 'C') {
      discounted_price =
          floor(discounted_price * pow(10, 1) + 0.5) / pow(10, 1);
    } else {
      discounted_price =
          floor(discounted_price * pow(10, 2) + 0.5) / pow(10, 2);
    }
    cout << '$' << discounted_price << '\n';
  }
  return 0;
}
