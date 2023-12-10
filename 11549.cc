#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  int count = 0;
  for (int i = 0; i < 5; ++i) {
    int guess;
    cin >> guess;
    if (guess == T) {
      ++count;
    }
  }
  cout << count;
  return 0;
}
