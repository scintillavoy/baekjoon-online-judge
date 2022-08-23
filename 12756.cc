#include <iostream>
using namespace std;

int main() {
  int atk_A, hp_A;
  int atk_B, hp_B;
  cin >> atk_A >> hp_A;
  cin >> atk_B >> hp_B;
  while (hp_A > 0 && hp_B > 0) {
    hp_A -= atk_B;
    hp_B -= atk_A;
  }
  if (hp_A <= 0) {
    if (hp_B <= 0) {
      cout << "DRAW";
    } else {
      cout << "PLAYER B";
    }
  } else {
    cout << "PLAYER A";
  }
  cout << endl;
}
