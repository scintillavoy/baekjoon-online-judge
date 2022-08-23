#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;

  map<string, int> books;
  while (N--) {
    string title;
    cin >> title;
    if (!books.count(title)) {
      books[title] = 0;
    }
    ++books[title];
  }

  string answer;
  int maxNum = 0;
  for (auto &book : books) {
    if (book.second > maxNum) {
      answer = book.first;
      maxNum = book.second;
    }
  }

  cout << answer;
  return 0;
}
