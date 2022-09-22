#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0, max_cost = 0;
  while (n--) {
    int cost;
    cin >> cost;
    sum += cost;
    if (max_cost < cost) {
      max_cost = cost;
    }
  }
  cout << sum - max_cost;
  return 0;
}
