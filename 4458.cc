#include <cctype>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (N--) {
    string sentence;
    getline(cin, sentence);
    sentence[0] = toupper(sentence[0]);
    cout << sentence << '\n';
  }
  return 0;
}
