#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (!N) {
            break;
        }
        int num[3];
        for (auto &x : num) {
            cin >> x;
        }
        if (num[1] - num[0] == num[2] - num[1]) {
            cout << N * (2*num[0] + (N-1)*(num[1]-num[0])) / 2;
        } else {
            cout << num[0] * (int(pow(num[1]/num[0], N)) - 1) /
                    (num[1]/num[0] - 1);
        }
        cout << '\n';
    }
    return 0;
}
