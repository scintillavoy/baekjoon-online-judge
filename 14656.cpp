#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        if (i != num) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
