#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int arr[10000] = {0, };
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        ++arr[num - 1];
    }
    for (int i = 0; i < 10000; ++i) {
        while (--arr[i] >= 0) {
            cout << i + 1 << '\n';
        }
    }
    return 0;
}
