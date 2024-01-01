#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  if (b <= a) {
    cout << "Congratulations, you are within the speed limit!";
  } else {
    cout << "You are speeding and your fine is $";
    if (b <= a + 20) {
      cout << 100;
    } else if (b <= a + 30) {
      cout << 270;
    } else {
      cout << 500;
    }
    cout << '.';
  }
  return 0;
}
