#include <iostream>
using namespace std;

int main() {
  bool isSuccessful = true;
  for (int i = 0; i < 8; ++i) {
    int N;
    cin >> N;
    if (N == 9) {
      isSuccessful = false;
    }
  }
  cout << (isSuccessful ? 'S' : 'F') << '\n';
  return 0;
}
