#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_map<string, int> m;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        if (m.count(name)) {
            ++m[name];
        } else {
            m[name] = 1;
        }
    }
    for (int i = 0; i < N - 1; ++i) {
        string name;
        cin >> name;
        --m[name];
    }
    for (auto const &x : m) {
        if (x.second) {
            cout << x.first;
            break;
        }
    }
    return 0;
}
