#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string str;
        cin >> str;
        int len = sqrt(str.size());
        vector< vector<char> > vec(len,
                                    vector<char>(len));
        for (int j = 0; j < len; ++j) {
            for (int k = 0; k < len; ++k) {
                vec[j][k] = str[j * len + k];
            }
        }
        for (int j = len - 1; j >= 0; --j) {
            for (int k = 0; k < len; ++k) {
                cout << vec[k][j];
            }
        }
        cout << '\n';
    }
    return 0;
}
