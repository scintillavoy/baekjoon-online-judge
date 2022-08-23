#include <iostream>
#include <string>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    string str;
    cin >> str;
    int cnt[6] = {M * N, };
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> str;
            for (int k = 0; k < N; ++k) {
                if (str[1 + k * 5] == '*') {
                    ++cnt[j + 1];
                }
            }
        }
        cin >> str;
    }
    
    for (int i = 0; i < 5; ++i) {
        cout << cnt[i] - cnt[i + 1] << ' ';
    }
    return 0;
}
