#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int answer = -1000, sum = 0;
        for (int i = 0; i < N; ++i) {
            int val;
            cin >> val;
            sum += val;
            if (answer < sum) {
                answer = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}
