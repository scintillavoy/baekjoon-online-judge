#include <iostream>
#include <string>
using namespace std;

int main() {
  while (true) {
    string name;
    int age, weight;
    cin >> name >> age >> weight;
    if (name == "#" && age == 0 && weight == 0) {
      break;
    }
    cout << name << ' ' << (age > 17 || weight >= 80 ? "Senior" : "Junior")
         << '\n';
  }
  return 0;
}
