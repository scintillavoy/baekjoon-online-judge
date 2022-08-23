#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end());
    for (auto const &x : vec) {
        if (x <= L) {
            ++L;
        } else {
            break;
        }
    }
    cout << L << '\n';
    return 0;
}
