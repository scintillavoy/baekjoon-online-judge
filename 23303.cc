#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  getline(cin, str);
  cout << ((str.find("D2") != string::npos || str.find("d2") != string::npos)
               ? "D2"
               : "unrated");
  return 0;
}
