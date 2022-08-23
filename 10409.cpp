#include <iostream>
using namespace std;

int main() {
    int n, T;
    cin >> n >> T;
    for (int i = 0; i < n; ++i) {
        int time;
        cin >> time;
        T -= time;
        if (T < 0) {
            for (int j = i + 1; j < n; ++j) {
                cin >> time;
            }
            cout << i;
            return 0;
        }
    }
    cout << n;
    return 0;
}
