#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    int sum = 0;
    pair<int, int> init, prev, curr;
    cin >> init.first >> init.second;
    curr = init;
    for (int i = 1; i < N; ++i) {
        prev = curr;
        cin >> curr.first >> curr.second;
        sum += abs(curr.first - prev.first) + abs(curr.second - prev.second);
    }
    sum += abs(curr.first - init.first) + abs(curr.second - init.second);
    cout << sum;
    return 0;
}
