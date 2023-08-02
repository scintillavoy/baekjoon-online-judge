#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  unordered_map<string, string> passwords;
  for (int i = 0; i < N; ++i) {
    string key, value;
    cin >> key >> value;
    passwords[key] = value;
  }
  for (int i = 0; i < M; ++i) {
    string key;
    cin >> key;
    cout << passwords[key] << '\n';
  }
  return 0;
}
