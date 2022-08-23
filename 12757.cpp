#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    map<int, int> m;
    while (N--) {
        int key, value;
        cin >> key >> value;
        m[key] = value;
    }
    while (M--) {
        int command;
        cin >> command;
        if (command == 1) {
            int key, value;
            cin >> key >> value;
            m[key] = value;
        } else if (command == 2) {
            int key, value;
            cin >> key >> value;
            auto it1 = m.lower_bound(key);
            if (it1 == m.begin() || it1 == m.end()) {
                if (it1 == m.end()) {
                    --it1;
                }
                if (abs(it1->first - key) <= K) {
                    it1->second = value;
                }
            } else {
                auto it2 = it1--;
                int diff1 = abs(it1->first - key);
                int diff2 = abs(it2->first - key);
                if (min(diff1, diff2) <= K) {
                    if (diff1 < diff2) {
                        it1->second = value;
                    } else if (diff1 > diff2) {
                        it2->second = value;
                    }
                }
            }
        } else if (command == 3) {
            int key;
            cin >> key;
            auto it1 = m.lower_bound(key);
            if (it1 == m.begin() || it1 == m.end()) {
                if (it1 == m.end()) {
                    --it1;
                }
                if (abs(it1->first - key) <= K) {
                    cout << it1->second;
                } else {
                    cout << -1;
                }
            } else {
                auto it2 = it1--;
                int diff1 = abs(it1->first - key);
                int diff2 = abs(it2->first - key);
                if (min(diff1, diff2) <= K) {
                    if (diff1 < diff2) {
                        cout << it1->second;
                    } else if (diff1 > diff2) {
                        cout << it2->second;
                    } else {
                        cout << '?';
                    }
                } else {
                    cout << -1;
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
