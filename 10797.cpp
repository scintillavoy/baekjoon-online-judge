#include <iostream>
using namespace std;

int main() {
    int d, cnt = 0;
    cin >> d;
    for (int i = 0; i < 5; ++i) {
        int num;
        cin >> num;
        if (num == d) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
