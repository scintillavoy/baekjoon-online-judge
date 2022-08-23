#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        int W = 0, triNum = 3;
        for (int j = 1; j <= n; ++j) {
            W += j * triNum;
            triNum += j + 2;
        }
        cout << W << '\n';
    }
    return 0;
}
