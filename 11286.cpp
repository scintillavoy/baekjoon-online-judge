#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(const int &a, const int &b) {
    if (abs(a) == abs(b)) {
        return a > b;
    } else {
        return abs(a) > abs(b);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> vec;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x) {
            vec.push_back(x);
            push_heap(vec.begin(), vec.end(), cmp);
        } else {
            if (vec.empty()) {
                cout << 0;
            } else {
                pop_heap(vec.begin(), vec.end(), cmp);
                cout << vec.back();
                vec.pop_back();
            }
            cout << '\n';
        }
    }
    return 0;
}
