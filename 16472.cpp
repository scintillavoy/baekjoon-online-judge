#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string str;
    cin >> N >> str;
    int maxLen = 1, alphabet[26] = {0}, cnt = 0, idx1 = 0, idx2;
    for (idx2 = 0; idx2 < str.size(); ++idx2) {
        if (alphabet[str[idx2] - 'a'] == 0) {
            if (cnt >= N) {
                if (maxLen < idx2 - idx1) {
                    maxLen = idx2 - idx1;
                }
                while (cnt >= N) {
                    --alphabet[str[idx1] - 'a'];
                    if (alphabet[str[idx1] - 'a'] == 0) {
                        --cnt;
                    }
                    ++idx1;
                }
            }
            ++cnt;
        }
        ++alphabet[str[idx2] - 'a'];
    }
    if (maxLen < idx2 - idx1) {
        maxLen = idx2 - idx1;
    }
    cout << maxLen << '\n';
    return 0;
}
