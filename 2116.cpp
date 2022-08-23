#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int opposite[6] = {5, 3, 4, 1, 2, 0}, sum[6] = {0};
    int down[6] = {1, 2, 3, 4, 5, 6}, up[6], dice[6];
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (auto &x : dice) {
            cin >> x;
        }
        for (int j = 0; j < 6; ++j) {
            up[dice[j] - 1] = dice[opposite[j]];
        }
        for (int j = 0; j < 6; ++j) {
            if (down[j] == 6 || up[down[j] - 1] == 6) {
                if (down[j] == 5 || up[down[j] - 1] == 5) {
                    sum[j] += 4;
                } else {
                    sum[j] += 5;
                }
            } else {
                sum[j] += 6;
            }
            down[j] = up[down[j] - 1];
        }
    }
    cout << *max_element(sum, sum + 6);
    return 0;
}
