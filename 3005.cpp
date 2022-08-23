#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> vec(R, vector<char>(C));
    for (auto &row : vec) {
        for (auto &x : row) {
            cin >> x;
        }
    }

    string firstWord, word;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (vec[i][j] == '#') {
                if (word.size() >= 2 &&
                    (firstWord.empty() || firstWord > word)) {
                    firstWord = word;
                }
                word.clear();
            } else {
                word.push_back(vec[i][j]);
            }
        }
        if (word.size() >= 2 &&
            (firstWord.empty() || firstWord > word)) {
            firstWord = word;
        }
        word.clear();
    }

    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < R; ++j) {
            if (vec[j][i] == '#') {
                if (word.size() >= 2 &&
                    (firstWord.empty() || firstWord > word)) {
                    firstWord = word;
                }
                word.clear();
            } else {
                word.push_back(vec[j][i]);
            }
        }
        if (word.size() >= 2 &&
            (firstWord.empty() || firstWord > word)) {
            firstWord = word;
        }
        word.clear();
    }

    cout << firstWord;
    return 0;
}
