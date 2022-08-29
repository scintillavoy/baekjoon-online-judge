#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  double A, B, C;
  cin >> A >> B >> C;
  double I, J, K;
  cin >> I >> J >> K;
  double cocktail = min({A / I, B / J, C / K});
  cout.precision(4);
  cout << fixed << A - I * cocktail << ' ' << B - J * cocktail << ' '
       << C - K * cocktail;
  return 0;
}
