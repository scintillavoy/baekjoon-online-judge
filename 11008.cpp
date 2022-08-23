#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string s, p;
        cin >> s >> p;
        int cnt = 0;
        for (int i = 0; (i = s.find(p, i)) != string::npos; ++cnt, i += p.size());
        cout << s.size() - cnt * (p.size() - 1) << '\n';
    }
    return 0;
}
