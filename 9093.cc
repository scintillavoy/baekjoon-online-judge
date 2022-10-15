#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
using namespace std;

int main() {
  int T;
  cin >> T;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (T--) {
    string sentence;
    getline(cin, sentence);
    istringstream iss(sentence);
    string word;
    while (iss >> word) {
      reverse(word.begin(), word.end());
      cout << word << ' ';
    }
    cout << '\n';
  }
  return 0;
}
