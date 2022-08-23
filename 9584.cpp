#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main() {
    string code;
    int n;
    cin >> code >> n;
    vector<pair<string, bool>> vec(n);
    int cnt = 0;
    for (auto &x : vec) {
        cin >> x.first;
        x.second = true;
        for (int i = 0; i < 9; ++i) {
            if (code[i] != '*' && code[i] != x.first[i]) {
                x.second = false;
                break;
            }
        }
        if (x.second) {
            ++cnt;
        }
    }

    cout << cnt << '\n';
    for (auto const &x : vec) {
        if (x.second) {
            cout << x.first << '\n';
        }
    }
    return 0;
}
