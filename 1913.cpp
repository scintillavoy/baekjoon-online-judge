// memory-oriented implementation
#include <iostream>
using namespace std;

int distance(int x, int y, int lower_bound, int upper_bound) {
    int dist = -1;
    for (int i = lower_bound, j = lower_bound; i <= upper_bound; ++i) {
        ++dist;
        if (i == x && j == y) {
            return dist;
        }
    }
    for (int i = upper_bound, j = lower_bound + 1; j <= upper_bound; ++j) {
        ++dist;
        if (i == x && j == y) {
            return dist;
        }
    }
    for (int i = upper_bound - 1, j = upper_bound; i >= lower_bound; --i) {
        ++dist;
        if (i == x && j == y) {
            return dist;
        }
    }
    for (int i = lower_bound, j = upper_bound - 1; j >= lower_bound; --j) {
        ++dist;
        if (i == x && j == y) {
            return dist;
        }
    }
    return -1;
}

int main() {
    int N, target_num, target_x, target_y;
    cin >> N >> target_num;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int lower_bound = 0, upper_bound = N - 1, num = N;
            while (i != lower_bound && i != upper_bound && \
                   j != lower_bound && j != upper_bound) {
                ++lower_bound, --upper_bound;
                num -= 2;
            }
            num *= num;
            num -= distance(i, j, lower_bound, upper_bound);
            cout << num << ' ';
            if (num == target_num) {
                target_x = i + 1, target_y = j + 1;
            }
        }
        cout << '\n';
    }
    cout << target_x << ' ' << target_y;
    return 0;
}
