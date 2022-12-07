#include <iostream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string s, p;
    cin >> s >> p;
    int count = 0;
    for (size_t i = 0; (i = s.find(p, i)) != string::npos;
         ++count, i += p.size())
      ;
    cout << s.size() - count * (p.size() - 1) << '\n';
  }
  return 0;
}
