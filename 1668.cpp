#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    int maxHeight = 0, cnt = 0;
    for (auto &x : vec) {
        cin >> x;
        if (maxHeight < x) {
            maxHeight = x;
            ++cnt;
        }
    }
    cout << cnt << '\n';
    maxHeight = 0, cnt = 0;
    for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
        if (maxHeight < *it) {
            maxHeight = *it;
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
