#include <iostream>
#include <limits>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
  unordered_set<string> strings{
      "Never gonna give you up",
      "Never gonna let you down",
      "Never gonna run around and desert you",
      "Never gonna make you cry",
      "Never gonna say goodbye",
      "Never gonna tell a lie and hurt you",
      "Never gonna stop",
  };
  int N;
  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  bool flag = false;
  while (N--) {
    string S;
    getline(cin, S);
    if (strings.count(S) == 0) {
      flag = true;
    }
  }
  cout << (flag ? "Yes" : "No");
  return 0;
}
