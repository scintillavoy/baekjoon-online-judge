#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> count(26);
  for (int i = 0; i < N; ++i) {
    string word;
    cin >> word;
    for (int i = word.size() - 1; i >= 0; --i) {
      count[word[i] - 'A'] += pow(10, word.size() - 1 - i);
    }
  }
  sort(count.begin(), count.end(), greater<int>());
  int max_sum = 0;
  for (int i = 0; i < count.size(); ++i) {
    max_sum += count[i] * (9 - i);
  }
  cout << max_sum;
  return 0;
}
