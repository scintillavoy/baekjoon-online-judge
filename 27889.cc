#include <iostream>
#include <string>
using namespace std;

int main() {
  string acronym;
  cin >> acronym;
  if (acronym == "NLCS") {
    cout << "North London Collegiate School";
  } else if (acronym == "BHA") {
    cout << "Branksome Hall Asia";
  } else if (acronym == "KIS") {
    cout << "Korea International School";
  } else if (acronym == "SJA") {
    cout << "St. Johnsbury Academy";
  }
  return 0;
}
