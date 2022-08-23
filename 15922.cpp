#include <iostream>
#include <utility>
using namespace std;

int main() {
    int N;
    cin >> N;
    int sum = 0;
    pair<int, int> prev, curr;
    cin >> prev.first >> prev.second;
    for (int i = 1; i < N; ++i) {
        cin >> curr.first >> curr.second;
        if (curr.first <= prev.second) {
            if (curr.second > prev.second) {
                prev.second = curr.second;
            }
        } else {
            sum += prev.second - prev.first;
            prev = curr;
        }
    }
    sum += prev.second - prev.first;
    cout << sum;
    return 0;
}
