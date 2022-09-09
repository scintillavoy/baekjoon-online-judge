#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  cin >> input;
  if (input[1] == '0') {
    cout << 10 + stoi(input.substr(2, string::npos));
  } else {
    cout << stoi(input.substr(0, 1)) + stoi(input.substr(1, string::npos));
  }
  return 0;
}
