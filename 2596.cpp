#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> vec = {"000000", "001111", "010011", "011100",
                          "100110", "101001", "110101", "111010"};

    int N;
    cin >> N;
    string input;
    cin >> input;

    string res;
    for (int i = 0; i < N; ++i) {
        string character = input.substr(i * 6, 6);
        int j;
        for (j = 0; j < 8; ++j) {
            int cnt = 0;
            for (int k = 0; k < 6; ++k) {
                if (character[k] != vec[j][k]) {
                    ++cnt;
                }
            }
            if (cnt <= 1) {
                res += 'A' + j;
                break;
            }
        }
        if (j == 8) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    cout << res << '\n';
    return 0;
}
