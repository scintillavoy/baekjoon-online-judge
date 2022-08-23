#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        string S_max;
        int L_max = -1;
        for (int j = 0; j < N; ++j) {
            string S;
            int L;
            cin >> S >> L;
            if (L > L_max) {
                S_max = S;
                L_max = L;
            }
        }
        cout << S_max << '\n';
    }
    return 0;
}
