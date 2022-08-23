#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    bitset<32> b(N);
    int cnt;
    for (cnt = 0; b.count() > K; ++cnt) {
        int i;
        for (i = 0; b[i] != 0; ++i) {
            b[i] = 0;
        }
        b[i] = 1;
    }
    cout << cnt;
    return 0;
}
