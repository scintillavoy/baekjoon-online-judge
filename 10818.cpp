#include <iostream>
#include <limits>
using namespace std;

int main() {
    int N;
    cin >> N;
    int minNum = numeric_limits<int>::max();
    int maxNum = numeric_limits<int>::min();
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (num > maxNum) {
            maxNum = num;
        }
        if (num < minNum) {
            minNum = num;
        }
    }
    cout << minNum << ' ' << maxNum;
    return 0;
}
