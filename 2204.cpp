#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (!n) {
            break;
        }
        string answer, word;
        cin >> answer;
        while (--n) {
            cin >> word;
            for (int i = 0; i < answer.size(); ++i) {
                if (i == word.size()) {
                    answer = word;
                    break;
                }
                if (tolower(answer[i]) != tolower(word[i])) {
                    if (tolower(answer[i]) > tolower(word[i])) {
                        answer = word;
                    }
                    break;
                }
            }
        }
        cout << answer << '\n';
    }
    return 0;
}
