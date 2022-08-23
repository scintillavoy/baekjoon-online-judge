#include <iostream>
using namespace std;

int main() {
    int N, arr[2001] = {0};
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        ++arr[num + 1000];
    }
    for (int i = 0; i < 2001; ++i) {
        if (arr[i] > 0) {
            cout << i - 1000 << ' ';
        }
    }
    return 0;
}
