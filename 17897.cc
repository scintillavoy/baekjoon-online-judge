#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool isAvailable = false;
  while (n--) {
    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string name;
    getline(cin, name);
    bool pea_soup = false, pancakes = false;
    while (k--) {
      string menu;
      getline(cin, menu);
      if (menu == "pea soup") {
        pea_soup = true;
      } else if (menu == "pancakes") {
        pancakes = true;
      }
    }
    if (pea_soup && pancakes && !isAvailable) {
      isAvailable = true;
      cout << name;
    }
  }
  if (!isAvailable) {
    cout << "Anywhere is fine I guess";
  }
  return 0;
}
