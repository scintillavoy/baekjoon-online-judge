#include <iostream>
using namespace std;

int main() {
  int day;
  cin >> day;
  int answer = 0;
  for (int i = 0; i < 5; ++i) {
    int number;
    cin >> number;
    if (day == number) {
      ++answer;
    }
  }
  cout << answer;
  return 0;
}
