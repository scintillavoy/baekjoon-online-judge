#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int n;
    cin >> n;
    int minNum = numeric_limits<int>::max();
    vector<int> vec(n);
    for (auto &x : vec) {
        cin >> x;
        if (x < minNum) {
            minNum = x;
        }
    }
    for (int i = 1; i <= minNum; ++i) {
        bool flag = true;
        for (auto &x : vec) {
            if (x % i != 0) {
                flag = false;
            }
        }
        if (flag) {
            cout << i << '\n';
        }
    }
    return 0;
}
