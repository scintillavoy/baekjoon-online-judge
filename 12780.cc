#include <iostream>
#include <string>
using namespace std;

int main() {
  string H, N;
  cin >> H >> N;
  int count = 0;
  size_t pos = 0UL;
  while (true) {
    pos = H.find(N, pos);
    if (pos != string::npos) {
      ++count;
      ++pos;
    } else {
      break;
    }
  }
  cout << count;
  return 0;
}
