#include <iostream>
#include <limits>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  vector<queue<string>> vec;
  while (N--) {
    string line;
    getline(cin, line);
    istringstream iss(line);
    queue<string> words;
    string word;
    while (getline(iss, word, ' ')) {
      words.push(word);
    }
    vec.push_back(words);
  }
  string L;
  getline(cin, L);
  istringstream iss(L);
  string word;
  while (getline(iss, word, ' ')) {
    bool matched = false;
    for (auto &q : vec) {
      if (q.empty() || q.front() != word) continue;
      q.pop();
      matched = true;
      break;
    }
    if (!matched) {
      cout << "Impossible";
      return 0;
    }
  }
  for (const auto &q : vec) {
    if (!q.empty()) {
      cout << "Impossible";
      return 0;
    }
  }
  cout << "Possible";
  return 0;
}
