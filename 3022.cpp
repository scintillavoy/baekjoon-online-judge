#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_map<string, int> m;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        if (m.count(name)) {
            if (m[name] > i - m[name]) {
                ++cnt;
            }
            ++m[name];
        } else {
            m[name] = 1;
        }
    }
    cout << cnt;
    return 0;
}
