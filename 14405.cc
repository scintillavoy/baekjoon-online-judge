#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  for (int i = 0; i < S.size();) {
    switch (S[i]) {
      case 'p':
        if (S.substr(i, 2) != "pi") {
          cout << "NO";
          return 0;
        }
        i += 2;
        break;
      case 'k':
        if (S.substr(i, 2) != "ka") {
          cout << "NO";
          return 0;
        }
        i += 2;
        break;
      case 'c':
        if (S.substr(i, 3) != "chu") {
          cout << "NO";
          return 0;
        }
        i += 3;
        break;
      default:
        cout << "NO";
        return 0;
    }
  }
  cout << "YES";
  return 0;
}
