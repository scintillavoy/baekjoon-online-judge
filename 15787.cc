#include <bitset>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<bitset<20>> trains(N);
  while (M--) {
    int command;
    cin >> command;
    int i, x;
    switch (command) {
      case 1:
        cin >> i >> x;
        trains[i - 1][x - 1] = true;
        break;
      case 2:
        cin >> i >> x;
        trains[i - 1][x - 1] = false;
        break;
      case 3:
        cin >> i;
        trains[i - 1] <<= 1;
        break;
      case 4:
        cin >> i;
        trains[i - 1] >>= 1;
        break;
    }
  }
  unordered_set<bitset<20>> s;
  for (const auto &x : trains) {
    s.insert(x);
  }
  cout << s.size();
  return 0;
}
