#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, cnt = 0;
    cin >> N;
    string word;
    for (int i = 0; i < N; ++i) {
        cin >> word;
        ++cnt;
        if (word.size() <= 1) {
            continue;
        }
        int checker[26] = {0, };
        checker[word[0] - 'a'] = 1;
        for (auto it = word.cbegin() + 1; it != word.cend(); ++it) {
            if (*(it-1) != *it) {
                if (checker[*it - 'a']) {
                    --cnt;
                    break;
                } else {
                    checker[*it - 'a'] = 1;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
