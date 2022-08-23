#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> vec;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x) {
            vec.push_back(x);
            push_heap(vec.begin(), vec.end());
        } else {
            if (vec.empty()) {
                cout << 0;
            } else {
                pop_heap(vec.begin(), vec.end());
                cout << vec.back();
                vec.pop_back();
            }
            cout << '\n';
        }
    }
    return 0;
}
