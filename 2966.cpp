#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string id[3] = {"Adrian", "Bruno", "Goran"};
    string guess[3] = {"ABCABCABCABC", "BABCBABCBABC", "CCAABBCCAABB"};
    int cnt[3] = {0};
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        for (int j = 0; j < 3; ++j) {
            if (c == guess[j][i % 12]) {
                ++cnt[j];
            }
        }
    }
    int maxCnt = *max_element(cnt, cnt + 3);
    cout << maxCnt << '\n';
    for (int i = 0; i < 3; ++i) {
        if (cnt[i] == maxCnt) {
            cout << id[i] << '\n';
        }
    }
    return 0;
}
