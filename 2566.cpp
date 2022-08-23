#include <iostream>
#include <utility>
using namespace std;

int main() {
    int maxNum = 0;
    pair<int, int> maxPos;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int num;
            cin >> num;
            if (num > maxNum) {
                maxNum = num;
                maxPos.first = i;
                maxPos.second = j;
            }
        }
    }
    cout << maxNum << '\n';
    cout << maxPos.first + 1 << ' ' << maxPos.second + 1;
    return 0;
}
