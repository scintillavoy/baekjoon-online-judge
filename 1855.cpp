#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int K;
    string str;
    cin >> K >> str;
    vector< vector<char> > vec(K, vector<char>(str.size() / K));
    for (int i = 0; i < str.size(); ++i) {
        if (((i / K) % 2) == 0) {
            vec[i % K][i / K] = str[i];
        } else {
            vec[K - i % K - 1][i / K] = str[i];
        }
    }
    for (auto const &x : vec) {
        for (auto const &y : x) {
            cout << y;
        }
    }
    return 0;
}
