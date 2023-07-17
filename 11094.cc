#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (N--) {
    string str;
    getline(cin, str);
    if (str.substr(0, 10) == "Simon says") {
      cout << str.substr(10) << '\n';
    }
  }
  return 0;
}
