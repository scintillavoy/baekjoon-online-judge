#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int J;
  cin >> J;
  int basket_position = 1;
  int min_distance = 0;
  while (J--) {
    int apple_position;
    cin >> apple_position;
    if (apple_position < basket_position) {
      min_distance += basket_position - apple_position;
      basket_position = apple_position;
    } else if (basket_position + M - 1 < apple_position) {
      min_distance += apple_position - basket_position - M + 1;
      basket_position = apple_position - M + 1;
    }
  }
  cout << min_distance;
  return 0;
}
