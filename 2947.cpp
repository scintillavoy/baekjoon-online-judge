#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    vector<int> vec(5);
    for (auto &x : vec) {
        cin >> x;
    }
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < vec.size() - 1; ++i) {
            if (vec[i] > vec[i + 1]) {
                flag = true;
                swap(vec[i], vec[i + 1]);
                for (auto const &x : vec) {
                    cout << x << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
