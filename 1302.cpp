#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<string, int> m;
    while (N--) {
        string title;
        cin >> title;
        if (m.count(title)) {
            ++m[title];
        } else {
            m[title] = 1;
        }
    }
    pair<string, int> best("init", 0);
    for (auto const &x : m) {
        if (x.second > best.second) {
            best = x;
        }
    }
    cout << best.first;
    return 0;
}
