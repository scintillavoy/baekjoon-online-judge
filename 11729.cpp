#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int lv, int source, int dest, int other) {
    if (lv == 0) {
        return;
    }
    hanoi(lv - 1, source, other, dest);
    cout << source << ' ' << dest << '\n';
    hanoi(lv - 1, other, dest, source);
}

int main() {
    int N;
    cin >> N;
    cout << (long long) pow(2, N) - 1 << '\n';
    hanoi(N, 1, 3, 2);
    return 0;
}
