#include <iostream>
#include <vector>
using namespace std;

#define MAX 100'000

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, T;
  cin >> N >> T;
  vector<int> vec(MAX + 1);
  for (int i = 0; i < N; ++i) {
    int K;
    cin >> K;
    for (int j = 0; j < K; ++j) {
      int S, E;
      cin >> S >> E;
      ++vec[S];
      --vec[E];
    }
  }
  for (int i = 1; i < vec.size(); ++i) {
    vec[i] += vec[i - 1];
  }
  long long current_value = 0;
  for (int i = 0; i < T; ++i) {
    current_value += vec[i];
  }
  long long max_value = current_value;
  int max_start_time = 0;
  int max_end_time = T;
  for (int i = T; i < vec.size(); ++i) {
    current_value += vec[i] - vec[i - T];
    if (max_value < current_value) {
      max_value = current_value;
      max_start_time = i - T + 1;
      max_end_time = i + 1;
    }
  }
  cout << max_start_time << ' ' << max_end_time;
  return 0;
}
