#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  double weight;
  cout.precision(2);
  cout << fixed;
  while (cin >> weight) {
    if (weight < 0) {
      break;
    }
    cout << "Objects weighing " << weight << " on Earth will weigh "
         << weight * 0.167 << " on the moon.\n";
  }
  return 0;
}
