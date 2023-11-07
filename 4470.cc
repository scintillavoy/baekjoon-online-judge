#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for (int i = 1; i <= N; ++i) {
    string line;
    getline(cin, line);
    cout << i << ". " << line << '\n';
  }
  return 0;
}
