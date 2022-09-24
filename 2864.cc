#include <iostream>
#include <string>
using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  for (auto &x : A) {
    if (x == '6') {
      x = '5';
    }
  }
  for (auto &x : B) {
    if (x == '6') {
      x = '5';
    }
  }
  cout << stoi(A) + stoi(B);
  for (auto &x : A) {
    if (x == '5') {
      x = '6';
    }
  }
  for (auto &x : B) {
    if (x == '5') {
      x = '6';
    }
  }
  cout << ' ' << stoi(A) + stoi(B);
  return 0;
}
