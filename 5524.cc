#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  while (N--) {
    string name;
    cin >> name;
    for (int i = 0; i < name.size(); ++i) {
      cout << (char)tolower(name[i]);
    }
    cout << '\n';
  }
  return 0;
}
