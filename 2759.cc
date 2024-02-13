#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> numbers(N + 1);
    for (int i = 1; i <= N; ++i) {
      cin >> numbers[i];
    }
    vector<int> answer;
    for (int i = N; i > 0; --i) {
      if (numbers[i] == i) {
        continue;
      }
      if (numbers[1] != i) {
        for (int j = 2; j < i; ++j) {
          if (numbers[j] == i) {
            reverse(numbers.begin() + 1, numbers.begin() + j + 1);
            answer.push_back(j);
          }
        }
      }
      reverse(numbers.begin() + 1, numbers.begin() + i + 1);
      answer.push_back(i);
    }
    cout << answer.size();
    for (int i = 0; i < answer.size(); ++i) {
      cout << ' ' << answer[i];
    }
    cout << '\n';
  }
  return 0;
}
