#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for (int i = 0; i < N; ++i) {
    string number;
    getline(cin, number);
    cout << ((number.back() - '0') % 2 == 1 ? "odd" : "even") << '\n';
  }
  return 0;
}
