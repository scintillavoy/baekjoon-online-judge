#include <iostream>
#include <string>
using namespace std;

int main() {
  bool found = false;
  for (int i = 1; i <= 5; ++i) {
    string name;
    cin >> name;
    if (name.find("FBI") != string::npos) {
      found = true;
      cout << i << '\n';
    }
  }
  if (!found) {
    cout << "HE GOT AWAY!";
  }
  return 0;
}
