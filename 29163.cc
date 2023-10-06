#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int num_of_odds = 0;
  int num_of_evens = 0;
  while (n--) {
    int a;
    cin >> a;
    if (a % 2 == 0) {
      ++num_of_evens;
    } else {
      ++num_of_odds;
    }
  }
  if (num_of_evens > num_of_odds) {
    cout << "Happy";
  } else {
    cout << "Sad";
  }
  return 0;
}
