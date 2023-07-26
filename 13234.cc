#include <iostream>
#include <string>
using namespace std;

int main() {
  bool value1, value2;
  string operation;
  cin >> boolalpha >> value1 >> operation >> value2;
  cout << boolalpha;
  if (operation == "AND") {
    cout << (value1 && value2);
  } else if (operation == "OR") {
    cout << (value1 || value2);
  }
  return 0;
}
