#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  string str;
  cin >> str;
  string str2;
  for (int i = 0; i < str.size(); ++i) {
    str2.push_back(str[i]);
    if (str2.size() >= 4 && str2.substr(str2.size() - 4) == "PPAP") {
      for (int j = 0; j < 3; ++j) {
        str2.pop_back();
      }
    }
  }
  cout << (str2 == "P" ? "PPAP" : "NP");
  return 0;
}
