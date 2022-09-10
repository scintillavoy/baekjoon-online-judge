#include <iostream>
#include <string>
using namespace std;

int main() {
  string word;
  cin >> word;
  for (int i = 0; i < word.size(); ++i) {
    cout << word[i];
    if (i % 10 == 9) {
      cout << '\n';
    }
  }
  return 0;
}
