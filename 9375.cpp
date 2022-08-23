#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        unordered_map<string, int> m;
        int n;
        cin >> n;
        while (n--) {
            string a, b;
            cin >> a >> b;
            if (m.count(b)) {
                ++m[b];
            } else {
                m[b] = 1;
            }
        }
        int answer = 1;
        for (auto const &x : m) {
            answer *= x.second + 1;
        }
        cout << answer - 1 << '\n';
    }
    return 0;
}
