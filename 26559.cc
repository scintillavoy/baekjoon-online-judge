#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    map<int, string, greater<int>> friends;
    while (m--) {
      string name;
      int num;
      cin >> name >> num;
      friends[num] = name;
    }
    cout << friends.cbegin()->second;
    for (auto it = ++friends.cbegin(); it != friends.cend(); ++it) {
      cout << ", " << it->second;
    }
    cout << '\n';
  }
  return 0;
}
