#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  string pattern;
  cin >> pattern;
  for (int i = 2; i <= N; ++i) {
    string filename;
    cin >> filename;
    for (int i = 0; i < pattern.size(); ++i) {
      if (pattern[i] != filename[i]) {
        pattern[i] = '?';
      }
    }
  }
  cout << pattern;
  return 0;
}
