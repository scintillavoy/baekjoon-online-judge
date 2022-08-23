#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int df1 = 0;
    for (int i = 0; i < N; ++i) {
        int C, K;
        cin >> C >> K;
        df1 += C * K;
    }
    cout << df1;
    return 0;
}
