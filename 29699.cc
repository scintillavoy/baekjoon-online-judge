#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  string s("WelcomeToSMUPC");
  cout << s[(N - 1) % 14];
  return 0;
}
