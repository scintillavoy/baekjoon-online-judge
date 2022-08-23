#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int prize_max = 0;
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        int prize;
        if (a == b && b == c) {
            prize = 10000 + b * 1000;
        } else if (a == b || b == c) {
            prize = 1000 + b * 100;
        } else if (a == c) {
            prize = 1000 + a * 100;
        } else {
            prize = max({a, b, c}) * 100;
        }
        if (prize > prize_max) {
            prize_max = prize;
        }
    }
    cout << prize_max;
    return 0;
}
