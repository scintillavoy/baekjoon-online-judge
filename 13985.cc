#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  string input;
  getline(cin, input);
  cout << (input[0] - '0' + input[4] - '0' == input[8] - '0' ? "YES" : "NO");
  return 0;
}
