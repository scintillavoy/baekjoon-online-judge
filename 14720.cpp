#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int target = 0, cnt = 0;
    for (int i = 0; i < N; ++i) {
        int milk;
        cin >> milk;
        if (milk == target) {
            ++cnt;
            target = (target + 1) % 3;
        }
    }
    cout << cnt;
    return 0;
}
