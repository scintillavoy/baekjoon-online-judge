#include <iostream>
#include <string>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    string line;
    cin >> line;
    for (auto it = line.crbegin(); it != line.crend(); ++it) {
      cout << *it;
    }
    cout << '\n';
  }
  return 0;
}
