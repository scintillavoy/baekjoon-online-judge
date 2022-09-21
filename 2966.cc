#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string id[3] = {"Adrian", "Bruno", "Goran"};
  string guess[3] = {"ABCABCABCABC", "BABCBABCBABC", "CCAABBCCAABB"};
  int count[3] = {0};
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    char c;
    cin >> c;
    for (int j = 0; j < 3; ++j) {
      if (c == guess[j][i % 12]) {
        ++count[j];
      }
    }
  }
  int max_count = *max_element(count, count + 3);
  cout << max_count << '\n';
  for (int i = 0; i < 3; ++i) {
    if (count[i] == max_count) {
      cout << id[i] << '\n';
    }
  }
  return 0;
}
