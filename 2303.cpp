#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int winner, winNum = 0;
    for (int i = 0; i < N; ++i) {
        int arr[5], sum = 0, maxNum = 0;
        for (auto &x : arr) {
            cin >> x;
            sum += x;
        }
        for (int j = 0; j < 4; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                if ((sum - arr[j] - arr[k]) % 10 > maxNum) {
                    maxNum = (sum - arr[j] - arr[k]) % 10;
                }
            }
        }
        if (maxNum >= winNum) {
            winNum = maxNum;
            winner = i + 1;
        }
    }
    cout << winner;
    return 0;
}
