#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<string> working;
  while (n--) {
    string name, action;
    cin >> name >> action;
    if (action == "enter") {
      working.insert(name);
    } else {
      working.erase(name);
    }
  }
  for (auto it = working.rbegin(); it != working.rend(); ++it) {
    cout << *it << '\n';
  }
  return 0;
}
