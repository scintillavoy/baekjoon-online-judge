#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> weights(3);
  for (auto &weight : weights) {
    cin >> weight;
  }
  sort(weights.begin(), weights.end());
  cout << weights[1];
  return 0;
}
