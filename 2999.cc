#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string message;
  cin >> message;
  int R = floor(sqrt(message.size()));
  while (message.size() % R != 0) --R;
  int C = message.size() / R;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cout << message[i + j * R];
    }
  }
  return 0;
}
