#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  while (N--) {
    string password;
    cin >> password;
    cout << (password.size() >= 6 && password.size() <= 9 ? "yes" : "no")
         << '\n';
  }
  return 0;
}
