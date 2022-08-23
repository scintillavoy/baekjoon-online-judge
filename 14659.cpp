#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int highest = 0, maxCnt = 0, cnt = 0;
    while (N--) {
        int height;
        cin >> height;
        if (highest < height) {
            if (maxCnt < cnt) {
                maxCnt = cnt;
            }
            cnt = 0;
            highest = height;
        } else {
            ++cnt;
        }
    }
    cout << max(maxCnt, cnt);
    return 0;
}
