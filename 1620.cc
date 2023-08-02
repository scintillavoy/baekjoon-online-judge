#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  unordered_map<string, string> book;
  for (int i = 1; i <= N; ++i) {
    string name;
    cin >> name;
    book[name] = to_string(i);
    book[to_string(i)] = name;
  }
  for (int i = 0; i < M; ++i) {
    string input;
    cin >> input;
    cout << book[input] << '\n';
  }
  return 0;
}
