#include <iostream>
using namespace std;

int main() {
    int N, cnt = 3;
    cin >> N;
    while (--N) {
        cnt += cnt - 1; 
    }
    cout << cnt * cnt;
    return 0;
}
