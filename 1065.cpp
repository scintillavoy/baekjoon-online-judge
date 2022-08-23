#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    bool isHanNum;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        isHanNum = true;
        if (i >= 100) {
            int diff = i % 10 - (i / 10) % 10;
            for (int div = 10; i / (div * 10) != 0; div *= 10) {
                if ((i / div) % 10 - (i / (div * 10)) % 10 != diff) {
                    isHanNum = false;
                    break;
                }
            }
        }
        if (isHanNum) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
