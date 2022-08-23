#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        if (m.count(str)) {
            ++m[str];
        } else {
            m[str] = 1;
        }
    }
    string word;
    int cnt = 0;
    for (auto const &x : m) {
        if (x.second >= cnt) {
            word = x.first;
            cnt = x.second;
        }
    }
    cout << word << ' ' << cnt;
    return 0;
}
