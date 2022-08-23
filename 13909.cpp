#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= sqrt(N); ++i) {
        ++cnt;
    }
    cout << cnt;
    return 0;
}
