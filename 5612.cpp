#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int maxNum = m;
    for (int i = 0; i < n; ++i) {
        int in, out;
        cin >> in >> out;
        m = m + in - out;
        if (m < 0) {
            maxNum = 0;
            break;
        }
        if (maxNum < m) {
            maxNum = m;
        }
    }
    cout << maxNum << '\n';
    return 0;
}
