#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<string, int> extensions;
  while (N--) {
    string filename;
    cin >> filename;
    string extension = filename.substr(filename.find('.') + 1);
    ++extensions[extension];
  }
  for (const auto &x : extensions) {
    cout << x.first << ' ' << x.second << '\n';
  }
  return 0;
}
