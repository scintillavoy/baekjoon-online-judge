#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int w;
  cin >> w;
  if (w >= 620) {
    cout << "Red";
  } else if (w >= 590) {
    cout << "Orange";
  } else if (w >= 570) {
    cout << "Yellow";
  } else if (w >= 495) {
    cout << "Green";
  } else if (w >= 450) {
    cout << "Blue";
  } else if (w >= 425) {
    cout << "Indigo";
  } else {
    cout << "Violet";
  }
  return 0;
}
