#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);
  string target("UCPC");
  int index = 0;
  for (const auto &x : input) {
    if (x == target[index]) {
      ++index;
    }
    if (index == target.size()) {
      break;
    }
  }
  cout << "I " << (index == target.size() ? "love" : "hate") << " UCPC";
  return 0;
}
